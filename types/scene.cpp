#include "scene.hpp"
#include "../engine/renderer.hpp"
#include "factories/objectFactory.hpp"
#include "context.hpp"

EditorScene::EditorScene()
{
	camera.position = { 0, 0 };
	camera.zoom = 25.0f;
}

void EditorScene::draw(Renderer& renderer, pipelineContext& ctx)
{
	ctx.camera = &camera;

	for (const auto& obj : objects) {
		renderer.draw(*obj, ctx);
	}
}

void EditorScene::update(const updateContext& ctx)
{
	ImGuiIO& io = ImGui::GetIO();
	if (ImGui::Begin("Camera")) {
		ImGui::SliderFloat2("Posição X/Y", &camera.position.x, -100.f, 100.f);
		ImGui::SliderFloat("Zoom", &camera.zoom, 0.1f, 50.f);
	}
	ImGui::End();

	if (ImGui::Begin("Cena")) {
		if (ImGui::Button("Criar Objeto")) {
			auto obj = std::make_unique<Object>(createRectangle());
			objects.push_back(std::move(obj));
		}
	}
	ImGui::End();

	if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !ImGui::GetIO().WantCaptureMouse) {
		ImGuiIO& io = ImGui::GetIO();

		float mouseX{ io.MousePos.x };
		float mouseY{ io.MousePos.y };

		float ndcX = (mouseX / ctx.screenWidth) * 2.0f - 1.0f;
		float ndcY = (mouseY / ctx.screenHeight) * -2.0f + 1.0f;

		vec3f ndcPos{ ndcX, ndcY, 1.0f };

		mat3 invProj = camera.getInverseProjectionMatrix();
		mat3 invView = camera.getInverseViewMatrix();

		vec3f WorldPos = invView * (invProj * ndcPos);

		for (std::unique_ptr<Object>& obj : objects) {
			if (obj->contains(WorldPos.x, WorldPos.y)) {
				selectedObject = obj.get();
			}
		}
	}

	if (selectedObject != nullptr) {
		if (ImGui::Begin("Inspetor")) {
			ImGui::SliderFloat2("Posição X/Y", &selectedObject->getTransform().position.x, -100.f, 100.f);
		}
		ImGui::End();
	}
}

EditorScene::~EditorScene()
{
}

