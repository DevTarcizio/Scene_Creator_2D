#pragma once
#include <SDL3/SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>
#include <memory>

#include "../types/scene.hpp"
#include "../types/context.hpp"
#include "renderer.hpp"

class App {
public:
	App(int w, int h);
	void run();

private:
	bool init();
	void shutdown();
	void processInput();
	void update();
	void renderScene();
	
	std::unique_ptr<Scene> ActiveScene;
	bool isRunning{ true };
	Uint64 lastTime;

	const int WIDTH;
	const int HEIGHT;
	Renderer renderer;
	pipelineContext ctx_p;
	updateContext ctx_u;

	SDL_Window* window = nullptr;
	SDL_Renderer* render = nullptr;
	SDL_Texture* texture = nullptr;
};