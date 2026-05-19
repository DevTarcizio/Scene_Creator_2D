#pragma once

struct vec2i {
	int x;
	int y;

	bool operator==(const vec2i& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const vec2i& other) const {
		return !(*this == other);
	}
};

struct vec2f {
	float x;
	float y;
};

struct vec4f {
	float x;
	float y;
	float z;
	float w;
};