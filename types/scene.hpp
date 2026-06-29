#pragma once
#include <vector>
#include <memory>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>
#include "object.hpp"
#include "gizmo.hpp"

class Renderer;
struct pipelineContext;

class Scene {
public:
	Scene() = default;

	virtual void draw(Renderer& renderer, pipelineContext& ctx) = 0;
	virtual void update(const updateContext& ctx) = 0;
	
	virtual ~Scene() = default;

protected:
	std::vector<std::unique_ptr<Object>> objects;
	Camera camera;
	Gizmo gizmo;
	Object* selectedObject = nullptr;
};

class EditorScene : public Scene {
public:
	EditorScene();

	void draw(Renderer& renderer, pipelineContext& ctx) override;
	void update(const updateContext& ctx) override;
	
	~EditorScene() override;
};