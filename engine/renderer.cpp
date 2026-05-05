#include "renderer.hpp"

Render::Render(int w, int h) : width(w), height(h), framebuffer(w* h, 0) 
{
}

bool Render::isInsideScreen(vertex& v) const
{
	if (v.position.x >= width || v.position.x < 0) {
		return false;
	}
	if (v.position.y >= height || v.position.y < 0) {
		return false;
	}

	return true;
}

void Render::setOnPixel(vertex& v)
{
	if (!isInsideScreen(v)) {
		std::cout << "Vertex off the screen";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = v.color.toRGBA();
}

void Render::setOffPixel(vertex& v)
{
	if (!isInsideScreen(v)) {
		std::cout << "Vertex off the screen";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = 0xFFFFFFFF;
}

uint32_t* Render::getFramebufferData()
{
	return framebuffer.data();
}

int Render::getWidth()
{
	return width;
}

int Render::getHeight()
{
	return height;
}
