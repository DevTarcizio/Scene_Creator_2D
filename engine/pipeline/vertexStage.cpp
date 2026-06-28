#include "vertexStage.hpp"

VertexStage::VertexStage(int width, int height) : width(width), height(height) {}

// Pega o vertice em NDC e faz a conversão para Screen Space, 
// além de repassar a cor para o novo vertice
screenVertex VertexStage::process(const vertexOut& v)
{
	screenVertex out;

	out.position.x = (v.position.x + 1.0f) * 0.5f * width;
	out.position.y = (1.0 - (v.position.y + 1.0f) * 0.5f) * height;
	out.color = v.color;
	out.uv = v.uv;

	return out;
}
