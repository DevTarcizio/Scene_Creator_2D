#include "texture.hpp"

Texture::Texture(const std::string& filepath)
{
	data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
	
	assert(data != nullptr && "Falha ao carregar o arquivo da textura!");
}

Texture::~Texture()
{
	stbi_image_free(data);
}

Color Texture::sample(vec2f uv) const
{
	int x = (int)(uv.x * width);
	if (x == width) x -= 1;

	int y = (int)(uv.y * height);
	if (y == height) y -= 1;

	int index = (y * width + x) * channels;

	float red = data[index] / 255.0f;
	float green = data[index + 1] / 255.0f;
	float blue = data[index + 2] / 255.0f;

	return Color(red, green, blue);
}
