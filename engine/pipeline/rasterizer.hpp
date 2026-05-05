#pragma once
#include "../../types/vertex.hpp"
#include "vertexStage.hpp"
#include <algorithm>

class Renderer;

class Rasterizer {
public:
	Rasterizer(int w, int h);

	void drawLine(vertexNDC v0, vertexNDC v1, Renderer& renderer);
	void drawTriangle();

private:
	int width;
	int height;

	VertexStage vs;
};