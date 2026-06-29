#include "gizmo.hpp"

Gizmo::Gizmo(): 
	arrowX(createArrow({ 1.0f, 0.0f, 0.0f, 1.0f }, 0)), 
	arrowY(createArrow({ 0.0f, 1.0f, 0.0f, 1.0f }, 90))
{
}

void Gizmo::attachTo(Object* target)
{
	targetObject = target;

	arrowX.getTransform().position.x = targetObject->getTransform().position.x + targetObject->getTransform().scale.x / 2.0f;
	arrowX.getTransform().position.y = targetObject->getTransform().position.y;
	
	arrowY.getTransform().position.y = targetObject->getTransform().position.y + targetObject->getTransform().scale.y / 2.0f;
	arrowY.getTransform().position.x = targetObject->getTransform().position.x;
}

void Gizmo::draw(Renderer& renderer, pipelineContext& ctx)
{
	renderer.draw(arrowX, ctx);
	renderer.draw(arrowY, ctx);
}
