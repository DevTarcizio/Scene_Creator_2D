#pragma once

class VertexShader;
class FragmentShader;

struct pipelineContext {
	VertexShader* vs;
	FragmentShader* fs;
	float deltaTime;
	float time;
};