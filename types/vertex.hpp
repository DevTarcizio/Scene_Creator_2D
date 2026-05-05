#pragma once
#include "vec.hpp"
#include "color.hpp"

struct vertex {
	vec2i position;
	Color color;
};

struct vertexNDC {
	vec2f position;
	Color color;
};