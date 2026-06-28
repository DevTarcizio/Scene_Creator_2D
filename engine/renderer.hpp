#pragma once
#include "../types/object.hpp"
#include "../types/vertex.hpp"
#include "../types/context.hpp"
#include "pipeline/rasterizer.hpp"
#include "pipeline/vertexShader.hpp"
#include <vector>
#include <iostream>

class Rasterizer;

class Renderer {
public:
	Renderer(int w, int h);

	// Métodos dos pixel
	bool isInsideScreen(screenVertex& v) const;
	void setOnPixel(screenVertex& v);
	void setOffPixel(screenVertex& v);

	void draw(const Object& obj, pipelineContext& ctx);
	void clear(Color color);

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