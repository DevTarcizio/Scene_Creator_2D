#pragma once
#include "../../types/vertex.hpp"
#include "vertexStage.hpp"
#include "../../math/math.hpp"
#include <algorithm>

class Renderer;

class Rasterizer {
public:
	Rasterizer(int w, int h);

	void drawLine(vertexNDC v0, vertexNDC v1, Renderer& renderer);
	void drawTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2, Renderer& renderer);

private:
	int width;
	int height;

	VertexStage vs;
	math math;
};