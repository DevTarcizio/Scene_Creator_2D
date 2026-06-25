#pragma once
#include "vec.hpp"
#include "color.hpp"

struct fragment {
	vec2i position;
	Color color;
	vec2f uv;
};