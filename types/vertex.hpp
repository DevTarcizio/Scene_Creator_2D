#pragma once
#include "vec.hpp"
#include "color.hpp"

struct vertex {
	vec2i position;
	Color color;

	bool operator==(const vertex& other) const {
		return position.x == other.position.x && position.y == other.position.y;
	}

	bool operator!=(const vertex& other) const {
		return !(*this == other);
	}
};

struct vertexNDC {
	vec2f position;
	Color color;
};