#pragma once
#include "vec.hpp"

struct OrtographicProjection {
	float width = 100.f;
	float height = 100.f;
};

struct Camera {
	vec2f position = { 0.f, 0.f };
	vec2f viewport = { 100.f, 100.f };
	float zoom = 1.f;
};