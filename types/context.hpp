#pragma once
#include "transform.hpp"
#include "camera.hpp"

struct pipelineContext {
	float deltaTime;
	float time;
	Camera* camera;
};