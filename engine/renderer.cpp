#include "renderer.hpp"

Renderer::Renderer(int w, int h) : width(w), height(h), framebuffer(w * h, 0), rasterizer(w, h)
{
}

bool Renderer::isInsideScreen(vertex& v) const
{
	if (v.position.x >= width || v.position.x < 0) {
		return false;
	}
	if (v.position.y >= height || v.position.y < 0) {
		return false;
	}

	return true;
}

void Renderer::setOnPixel(vertex& v)
{
	if (!isInsideScreen(v)) {
		std::cout << "Vertex off the screen";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = v.color.toRGBA();
}

void Renderer::setOffPixel(vertex& v)
{
	if (!isInsideScreen(v)) {
		std::cout << "Vertex off the screen";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = 0xFFFFFFFF;
}

void Renderer::draw(vertexNDC v0, vertexNDC v1)
{
	rasterizer.drawLine(v0, v1, *this);
}

void Renderer::draw(vertexNDC v0, vertexNDC v1, vertexNDC v2)
{
	rasterizer.drawTriangle(v0, v1, v2, *this);
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
