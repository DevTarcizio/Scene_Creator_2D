#pragma once
#include "../../types/vertex.hpp"

class VertexStage {
public:
	VertexStage(int width, int height);

	screenVertex process(const vertexOut& v);

private:
	int width;
	int height;
};