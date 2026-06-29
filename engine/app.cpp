#include "app.hpp"

App::App(int w, int h) : WIDTH(w), HEIGHT(h), renderer(w, h)
{
	lastTime = SDL_GetTicks();
}

bool App::init()
{
	//===============================================================
	// Inicializando SDL
	//===============================================================
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("failed");
		return false;
	}

	window = SDL_CreateWindow("Scene Creator 2D", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
	if (!window) return false;
	render = SDL_CreateRenderer(window, 0);
	if (!render) return false;
	// Usando pixelformat ABGR pois assiim o RGBA é usado, e vice-versa
	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	if (!texture) return false;
	//===============================================================

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

	//===============================================================
	// Conexão da Scena a ActiveScene
	//===============================================================
	ActiveScene = std::make_unique<EditorScene>();
	//===============================================================
	return true;
}

void App::shutdown()
{
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

void App::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

			// Processamento de eventos nas janelas do ImGui
			ImGui_ImplSDL3_ProcessEvent(&event);

			if (event.type == SDL_EVENT_QUIT) {
				this->isRunning = false;
			}

	}
}

void App::update()
{
	// Cálculo de tempo
	Uint64 currentTime = SDL_GetTicks();
	float deltaTime = (currentTime - lastTime) / 1000.f;
	lastTime = currentTime;
	ctx_p.deltaTime = deltaTime;
	ctx_p.time += deltaTime;
	ctx_u.deltaTime = deltaTime;
	ctx_u.time += deltaTime;

	SDL_GetWindowSize(window, &ctx_u.screenWidth, &ctx_u.screenHeight);

	//===========================================================
	// Lógica do ImGui
	//===========================================================
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();

	ImGuiIO& io = ImGui::GetIO();
	if (ImGui::Begin("Engine Stats")) {
		ImGui::Text("Desempenho: %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
	}
	ImGui::End();
	//===========================================================

	if (ActiveScene) {
		ActiveScene->update(ctx_u);
	}
}

void App::renderScene()
{
	renderer.clear({ 0.0f, 0.0f, 0.0f, 1.0f });

	if (ActiveScene) {
		ActiveScene->draw(renderer, ctx_p);
	}

	SDL_UpdateTexture(texture, nullptr, renderer.getFramebufferData(), WIDTH * sizeof(uint32_t));
	SDL_RenderClear(render);
	SDL_RenderTexture(render, texture, nullptr, nullptr);
	
	// Renderização do ImGui
	ImGui::Render();
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), render);

	SDL_RenderPresent(render);
}

void App::run()
{
	if (init()) {
		while (isRunning) {
			processInput();
			update();
			renderScene();
		}
	}
	shutdown();
}