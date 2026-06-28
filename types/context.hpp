#pragma once
#include "texture.hpp"
#include "camera.hpp"

struct pipelineContext {
	float deltaTime;
	float time;
	Camera* camera;
	Texture* activeTexture;
};

struct updateContext {
	float time;
	float deltaTime;
	int screenWidth;
	int screenHeight;
};