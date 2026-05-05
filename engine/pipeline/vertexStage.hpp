#pragma once
#include "../../types/vertex.hpp"
#include "../renderer.hpp"

class VertexStage {
public:
	VertexStage();

	vertex process(const vertexNDC& ndc);
};