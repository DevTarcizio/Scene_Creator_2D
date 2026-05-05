#pragma once
#include "../types/vertex.hpp"
#include <vector>

class Render {
public:
	Render(int w, int h);

	
	bool isInsideScreen(vertex& v) const;
	void setOnPixel(vertex& v);
	void setOffPixel(vertex& v);

	// Getters
	uint32_t* getFramebufferData();
	int getWidth();
	int getHeight();

private:
	const int width{ 0 };
	const int height{ 0 };
	std::vector<uint32_t> framebuffer;
};