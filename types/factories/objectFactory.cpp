#include "objectFactory.hpp"

Object createRectangle()
{
	vertex v1, v2, v3, v4;

	v1.position = { -0.5f, 0.6f };
	v1.color = { 1.0f, 0.0f, 0.0f, 1.0f };
	v1.uv = { 0, 0 };

	v2.position = { -0.5f, -0.3f };
	v2.color = { 0.0f, 1.0f, 0.0f, 1.0f };
	v2.uv = { 0, 1 };

	v3.position = { 0.5f, -0.3f };
	v3.color = { 0.0f, 0.0f, 1.0f, 1.0f };
	v3.uv = { 1, 1 };

	v4.position = { 0.5f, 0.6f };
	v4.color = { 0.1f, 0.1f, 0.1f, 1.0f };
	v4.uv = { 1, 0 };

	auto* mesh = new Mesh(
		{
			v1, v2, v3, v4
		},
		{
			0, 1, 2,
			0, 2, 3
		}
	);

	auto* texture = new Texture("resources/textures/grass_block.png");

	Transform transform;
	Object obj(mesh, transform, texture);

	obj.setFragmentShader(new TextureFragmentShader());
	obj.setVertexShader(new SinVertexShader());

	return obj;
}