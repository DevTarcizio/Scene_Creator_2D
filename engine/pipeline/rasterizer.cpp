#include "rasterizer.hpp"
#include "../renderer.hpp"

Rasterizer::Rasterizer(int w, int h) : width(w), height(h), vs(width, height) {}

void Rasterizer::drawLine(vertexNDC v0, vertexNDC v1, Renderer& renderer)
{
	vertex vi{ vs.process(v0) };
	vertex vf{ vs.process(v1) };

	std::cout << vi.position.x << ", " << vi.position.y << "\n";
	std::cout << vf.position.x << ", " << vf.position.y << "\n";

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
		vertex p;

		p.position.x = (int)round(cords.x);
		p.position.y = (int)round(cords.y);
		p.color = vi.color;

		renderer.setOnPixel(p);
		
		cords.x += Xincrement;
		cords.y += Yincrement;
	}
}
