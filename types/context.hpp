#pragma once
#include "transform.hpp"
#include "camera.hpp"

class VertexShader;
class FragmentShader;

struct pipelineContext {
	VertexShader* vs = nullptr;
	FragmentShader* fs = nullptr;
	float deltaTime;
	float time;
	Transform transform;
	Camera* camera;
};