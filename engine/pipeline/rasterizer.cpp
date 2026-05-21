#include "rasterizer.hpp"
#include "../renderer.hpp"

Rasterizer::Rasterizer(int w, int h) : width(w), height(h), vertStage(width, height) {}

Color Rasterizer::applyFragmentShader(screenVertex& p, screenVertex& p0, screenVertex& p1, screenVertex& p2, float w0, float w1, float w2, pipelineContext& ctx)
{
	fragment frag;
	frag.position = p.position;

	frag.color =
		p0.color * w0 +
		p1.color * w1 +
		p2.color * w2;

	return ctx.fs->process(frag, ctx);
}

void Rasterizer::drawLine(vertexOut v0, vertexOut v1, Renderer& renderer)
{
	screenVertex vi{ vertStage.process(v0) };
	screenVertex vf{ vertStage.process(v1) };

	float distance_x{ static_cast<float>(vf.position.x - vi.position.x) };
	float distance_y{ static_cast<float>(vf.position.y - vi.position.y) };

	float steps{ std::max(std::abs(distance_x), std::abs(distance_y)) };

	if (steps == 0.0f) {
		renderer.setOnPixel(vi);
		return;
	}

	float Xincrement{ distance_x / steps };
	float Yincrement{ distance_y / steps };

	vec2f cords{
		(float)vi.position.x,
		(float)vi.position.y
	};


	for (int i{ 0 }; i <= steps; i++) {
		screenVertex p;

		p.position.x = (int)round(cords.x);
		p.position.y = (int)round(cords.y);
		p.color = vi.color;

		renderer.setOnPixel(p);
		
		cords.x += Xincrement;
		cords.y += Yincrement;
	}
}

// Using Barycentric Coordinates
void Rasterizer::drawTriangle(vertexOut v0, vertexOut v1, vertexOut v2, Renderer& renderer, pipelineContext& ctx)
{
	screenVertex p0{ vertStage.process(v0) };
	screenVertex p1{ vertStage.process(v1) };
	screenVertex p2{ vertStage.process(v2) };

	int minX{ std::min(p0.position.x, std::min(p1.position.x, p2.position.x)) };
	int minY{ std::min(p0.position.y, std::min(p1.position.y, p2.position.y)) };
	int maxX{ std::max(p0.position.x, std::max(p1.position.x, p2.position.x)) };
	int maxY{ std::max(p0.position.y, std::max(p1.position.y, p2.position.y)) };

	minX = std::max(0, minX);
	minY = std::max(0, minY);
	maxX = std::min(maxX, renderer.getWidth() - 1);
	maxY = std::min(maxY, renderer.getHeight() - 1);

	float area{ (float)math.crossProduct(p0.position, p1.position, p2.position) };
	float inverseArea{ 1.0f / area };

	screenVertex p;
	for (int i{ minX }; i <= maxX; i++) {
		for (int j{ minY }; j <= maxY; j++) {
			
			p.position = { i, j };

			float a0{ (float)math.crossProduct(p.position, p1.position, p2.position) };
			float a1{ (float)math.crossProduct(p.position, p2.position, p0.position) };
			float a2{ (float)math.crossProduct(p.position, p0.position, p1.position) };

			float w0{ a0 * inverseArea };
			float w1{ a1 * inverseArea };
			float w2{ a2 * inverseArea };

			// Se isso for verdade o ponto P está dentro do triangulo
			if ((w0 >= 0 && w1 >= 0 && w2 >= 0) || (w0 <= 0 && w1 <= 0 && w2 <= 0)) {
				Color c = applyFragmentShader(p, p0, p1, p2, w0, w1, w2, ctx);
				p.color = c;
				renderer.setOnPixel(p);
			}
		}
	}
}

void Rasterizer::drawMesh(Mesh m, pipelineContext& ctx) {
	for (size_t i{ 0 }; i < m.getIndices().size(); i += 3) {
	}
}
