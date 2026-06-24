#pragma once
#include "vec.hpp"
#include "mat.hpp"

struct Camera {
	vec2f position = { 0.f, 0.f };
	vec2f viewport = { 100.f, 100.f };
	float zoom = 25.f;

	mat3 getViewMatrix() const
	{
		mat3 translationMatrix = mat3::translation(-position.x, -position.y);
		mat3 scaleMatrix = mat3::scale(zoom, zoom);

		return scaleMatrix * translationMatrix;
	}

	mat3 getProjectionMatrix() const 
	{
		mat3 projectionMatrix = mat3::scale(2.0f / viewport.x, 2.0f / viewport.y);
		return projectionMatrix;
	}
};