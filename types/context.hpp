#pragma once
#include "transform.hpp"

class VertexShader;
class FragmentShader;

struct pipelineContext {
	VertexShader* vs = nullptr;
	FragmentShader* fs = nullptr;
	float deltaTime;
	float time;
	Transform transform;
};