#include "scene.hpp"
#include "../engine/renderer.hpp"
#include "factories/objectFactory.hpp"
#include "context.hpp"

EditorScene::EditorScene() 
{
	camera.position = { 0, 0 };
	camera.zoom = 25.0f;

	auto obj = std::make_unique<Object>(createRectangle());
	objects.push_back(std::move(obj));
}

void EditorScene::draw(Renderer& renderer, pipelineContext& ctx)
{
	ctx.camera = &camera;

	for (const auto& obj : objects) {
		renderer.draw(*obj, ctx);
	}
}

void EditorScene::update()
{
	ImGuiIO& io = ImGui::GetIO();
	if (ImGui::Begin("Camera")) {
		ImGui::SliderFloat2("Posição X/Y", &camera.position.x, -100.f, 100.f);
		ImGui::SliderFloat("Zoom", &camera.zoom, 0.1f, 50.f);
	}
	ImGui::End();
}

EditorScene::~EditorScene()
{
}
