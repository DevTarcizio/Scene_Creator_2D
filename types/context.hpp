#pragma once
#include "../engine/pipeline/fragmentShader.hpp"
#include "../engine/pipeline/vertexShader.hpp"
#include "../engine/renderer.hpp"

struct pipelineContext {
	VertexShader* vs;
	fragmentShader* fs
};