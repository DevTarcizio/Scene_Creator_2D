#pragma once
#include "../../types/vertex.hpp"
#include "vertexStage.hpp"
#include "../../math/math.hpp"
#include <algorithm>

class Renderer;

class Rasterizer {
public:
	Rasterizer(int w, int h);

	void drawLine(vertexOut v0, vertexOut v1, Renderer& renderer);
	void drawTriangle(vertexOut v0, vertexOut v1, vertexOut v2, Renderer& renderer);

private:
	int width;
	int height;

	VertexStage vs;
	math math;
};