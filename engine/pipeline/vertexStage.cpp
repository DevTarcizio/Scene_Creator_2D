#include "vertexStage.hpp"

VertexStage::VertexStage() {}

vertex VertexStage::process(const vertexNDC& ndc)
{
	vertex out;

	out.position.x = ((ndc.position.x + 1.0f) * 0.5f) * WIDTH;
	out.position.y = (1.0 - (ndc.position.y + 1.0f) * 0.5f) * HEIGHT;
	out.color = ndc.color;

	return out;
}
