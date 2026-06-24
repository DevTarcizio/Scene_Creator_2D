#include <SDL3/SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>

#include "engine/renderer.hpp"
#include "engine/pipeline/vertexShader.hpp"
#include "engine/pipeline/fragmentShader.hpp"
#include "types/context.hpp"
#include "types/mesh.hpp"
#include "types/object.hpp"
#include "types/factories/objectFactory.hpp"

int main() {

	// Criação do object
	Object obj = createRectangle();
	pipelineContext context{};

	Camera c;
	context.camera = &c;

	// Fluxo de janela
	const int width{ 640 };
	const int height{	480 };

	Renderer renderer(width, height);

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("failed");
		return -1;
	};

	SDL_Window* window;
	window = SDL_CreateWindow("CPU Renderer", width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

	SDL_Renderer* render;
	render = SDL_CreateRenderer(window, 0);

	SDL_Texture* texture;
	// Usando pixelformat ABGR pois assim ele usa como RGBA
	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STREAMING, width, height);


	//===============================================================
	// Inicializando ImGui
	//===============================================================

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplSDL3_InitForSDLRenderer(window, render);
	ImGui_ImplSDLRenderer3_Init(render);
	//===============================================================


	bool isRunning{ true };

	Uint64 lastTime = SDL_GetTicks();

	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			
			// Processamento de eventos nas janelas do ImGui
			ImGui_ImplSDL3_ProcessEvent(&event);

			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

		}

		Uint64 currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;
		context.deltaTime = deltaTime;
		context.time += deltaTime;
		

		//===========================================================
		// Lógica do ImGui
		//===========================================================
		
		ImGui_ImplSDLRenderer3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();

		if (ImGui::Begin("Camera")) {
			ImGui::Text("Desempenho: %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
			ImGui::Separator();

			ImGui::Text("Posição");
			ImGui::SliderFloat2("Posição X/Y", &c.position.x, -100.0f, 100.0f);

			ImGui::Text("Zoom");
			ImGui::SliderFloat(" ", &c.zoom, 0.1f, 100.0f);
		}
		ImGui::End();
		//===========================================================

		renderer.clear({ 0.0f, 0.0f, 0.0f, 1.0f });
		renderer.draw(obj, context);

		SDL_UpdateTexture(texture, nullptr, renderer.getFramebufferData(), width * sizeof(uint32_t));
		SDL_RenderClear(render);
		SDL_RenderTexture(render, texture, nullptr, nullptr);

		// Renderização do ImGui
		ImGui::Render();
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), render);

		SDL_RenderPresent(render);

		//SDL_Delay(16);
	}


	//===========================================================
	// Shutdown do SDL3 e do ImGui
	//===========================================================
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	//===========================================================

}