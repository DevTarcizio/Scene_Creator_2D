#pragma once
#include "../../types/vertex.hpp"

class VertexStage {
public:
	VertexStage(int width, int height);

	vertex process(const vertexNDC& ndc);

private:
	int width;
	int height;
};