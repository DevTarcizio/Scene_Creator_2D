#include "renderer.hpp"

Renderer::Renderer(int w, int h) : width(w), height(h), framebuffer(w * h, 0), rasterizer(w, h)
{
}

bool Renderer::isInsideScreen(screenVertex& v) const
{
	if (v.position.x >= width || v.position.x < 0) {
		return false;
	}
	if (v.position.y >= height || v.position.y < 0) {
		return false;
	}

	return true;
}

void Renderer::setOnPixel(screenVertex& v)
{
	if (!isInsideScreen(v)) {
		std::cout << "Vertex off the screen";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = v.color.toRGBA();
}

void Renderer::setOffPixel(screenVertex& v)
{
	if (!isInsideScreen(v)) {
		std::cout << "Vertex off the screen";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = 0xFFFFFFFF;
}

void Renderer::draw(vertex v0, vertex v1, VertexShader& shader)
{
	vertexOut out0 = shader.process(v0);
	vertexOut out1 = shader.process(v1);

	rasterizer.drawLine(out0, out1, *this);
}

void Renderer::draw(vertex v0, vertex v1, vertex v2, VertexShader& shader)
{
	vertexOut out0 = shader.process(v0);
	vertexOut out1 = shader.process(v1);
	vertexOut out2 = shader.process(v2);


	rasterizer.drawTriangle(out0, out1, out2, *this);
}

void Renderer::clear(Color color)
{
	uint32_t c = color.toRGBA();
	for (int i{ 0 }; i < framebuffer.size(); i++) {
		framebuffer[i] = c;
	}
}

uint32_t* Renderer::getFramebufferData()
{
	return framebuffer.data();
}

int Renderer::getWidth()
{
	return width;
}

int Renderer::getHeight()
{
	return height;
}
