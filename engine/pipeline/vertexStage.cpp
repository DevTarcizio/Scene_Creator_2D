#include "vertexStage.hpp"

VertexStage::VertexStage(int width, int height) : width(width), height(height) {}

// Pega o vertice em NDC e faz a conversão para Screen Space, 
// além de repassar a cor para o novo vertice
vertex VertexStage::process(const vertexNDC& ndc)
{
	vertex out;

	out.position.x = (ndc.position.x + 1.0f) * 0.5f * width;
	out.position.y = (1.0 - (ndc.position.y + 1.0f) * 0.5f) * height;
	out.color = ndc.color;

	return out;
}
