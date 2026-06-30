#pragma once
#include "vec.hpp"
#include "mat.hpp"

struct Transform {
	vec2f position{0.0f, 0.0f};
	vec2f scale{1.0f, 1.0f};
	float rotation = 0.0f;

	mat3 getModelMatrix() const {
		mat3 out{ mat3::identity() };

		mat3 s{ mat3::scale(scale.x, scale.y) };
		mat3 t{ mat3::translation(position.x, position.y) };
		mat3 r{ mat3::rotation(rotation) };

		out = t * r * s;

		return out;
	}
};