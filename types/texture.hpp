#pragma once
#include "color.hpp"
#include "vec.hpp"
#include "../external/stb_image/stb_image.h"
#include <string>
#include <cassert>

class Texture {
private:
	int width{ 0 };
	int height{ 0 };
	int channels{ 0 };
	unsigned char* data{ nullptr };

public:
	Texture(const std::string& filepath);
	~Texture();

	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;

	Color sample(vec2f uv) const;
};