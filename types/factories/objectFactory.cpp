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
	obj.setVertexShader(new NormalVertexShader());

	return obj;
}

Object createArrow(Color color, float rotationAngle)
{
	vertex v1, v2, v3, v4, v5, v6, v7;

	v1.position = { 0.0f, 0.05f };
	v1.color = color;
	
	v2.position = { 0.0f, -0.05f };
	v2.color = color;
	
	v3.position = { 0.8f, -0.05f };
	v3.color = color;
	
	v4.position = { 0.8f, 0.05f };
	v4.color = color;
	
	v5.position = { 0.8f, 0.15f };
	v5.color = color;
	
	v6.position = { 0.8f, -0.15f };
	v6.color = color;

	v7.position = { 1.0f, 0.0f };
	v7.color = color;

	auto* mesh = new Mesh(
		{
			v1, v2, v3,
			v4, v5, v6,
			v7
		},
		{
			0, 1, 2,
			0, 2, 3,
			4, 5, 6
		}
	);

	Texture* texture = nullptr;
	Transform transform;
	float angle = rotationAngle * (3.1415f / 180.f);

	transform.rotation = angle;

	Object obj(mesh, transform, texture);

	obj.setFragmentShader(new NormalFragmentShader());
	obj.setVertexShader(new NormalVertexShader());

	return obj;
}
