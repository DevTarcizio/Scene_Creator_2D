#pragma once
#include "../types/vertex.hpp"
#include "pipeline/rasterizer.hpp"
#include <vector>
#include <iostream>

class Rasterizer;

class Renderer {
public:
	Renderer(int w, int h);

	// Métodos dos pixel
	bool isInsideScreen(vertex& v) const;
	void setOnPixel(vertex& v);
	void setOffPixel(vertex& v);

	void draw(vertexNDC v0, vertexNDC v1);

	// Getters
	uint32_t* getFramebufferData();
	int getWidth();
	int getHeight();

private:
	const int width{ 0 };
	const int height{ 0 };
	std::vector<uint32_t> framebuffer;

	Rasterizer rasterizer;
};