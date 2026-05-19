#pragma once
#include "vec.hpp"
#include "color.hpp"

// EM NDC POR ENQUANTO, SERÁ TROCADO DEPOIS
struct vertex {
	vec2f position;
	Color color;

	
};

// EM NDC POR ENQUANTO, SERÁ TROCADO DEPOIS
struct vertexOut {
	vec4f position;
	Color color;
};

struct screenVertex {
	vec2i position;
	Color color;

	bool operator==(const vertex& other) const {
		return position.x == other.position.x && position.y == other.position.y;
	}

	bool operator!=(const vertex& other) const {
		return !(*this == other);
	}
};
