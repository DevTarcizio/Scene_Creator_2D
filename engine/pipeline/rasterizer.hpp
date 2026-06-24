#pragma once
#include "../../types/vertex.hpp"
#include "../../types/fragment.hpp"
#include "../../types/context.hpp"
#include "../../types/mesh.hpp"
#include "../../math/math.hpp"
#include "vertexStage.hpp"
#include "fragmentShader.hpp"
#include <algorithm>

class Renderer;

class Rasterizer {
public:
	Rasterizer(int w, int h);

	void bindFragmentShader(FragmentShader* fs);
	Color applyFragmentShader(
		screenVertex& p,
		screenVertex& p0,
		screenVertex& p1,
		screenVertex& p2,
		float w0, float w1, float w2,
		pipelineContext& ctx
	);

	void drawLine(vertexOut v0, vertexOut v1, Renderer& renderer);
	void drawTriangle(vertexOut v0, vertexOut v1, vertexOut v2, Renderer& renderer, pipelineContext& ctx);
	void drawMesh(Mesh m, pipelineContext& ctx);

private:
	int width;
	int height;

	VertexStage vertStage;
	math math;
	FragmentShader* currentFS = nullptr;
};