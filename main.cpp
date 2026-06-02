#include <SDL3/SDL.h>
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


	bool isRunning{ true };

	Uint64 lastTime = SDL_GetTicks();

	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

		}

		Uint64 currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;
		context.deltaTime = deltaTime;
		context.time += deltaTime;
		

		renderer.clear({ 0.0f, 0.0f, 0.0f, 1.0f });
		renderer.draw(obj, context);

		SDL_UpdateTexture(texture, nullptr, renderer.getFramebufferData(), width * sizeof(uint32_t));
		SDL_RenderClear(render);
		SDL_RenderTexture(render, texture, nullptr, nullptr);
		SDL_RenderPresent(render);

		SDL_Delay(16);
	}



	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();

}