#pragma once
#include "object.hpp"
#include "factories/objectFactory.hpp"
#include "../engine/renderer.hpp"

class Gizmo {
public:
	Gizmo();

	void attachTo(Object* target);
	void draw(Renderer& renderer, pipelineContext& ctx);

private:
	Object arrowX;
	Object arrowY;

	Object* targetObject = nullptr;
};