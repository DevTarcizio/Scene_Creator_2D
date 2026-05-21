#pragma once
#include "transform.hpp"

class VertexShader;
class FragmentShader;

struct pipelineContext {
	VertexShader* vs;
	FragmentShader* fs;
	float deltaTime;
	float time;
	Transform transform;
};