#pragma once
#include "vec.hpp"
#include <cmath>

struct mat3 {
	float m[3][3];

	vec3f operator*(const vec3f& v) const {
		vec3f out{};

		out.x = (m[0][0] * v.x) + (m[0][1] * v.y) + (m[0][2] * v.z);
		out.y = (m[1][0] * v.x) + (m[1][1] * v.y) + (m[1][2] * v.z);
		out.z = (m[2][0] * v.x) + (m[2][1] * v.y) + (m[2][2] * v.z);
	
		return out;
	}

	mat3 operator*(const mat3& other) const {
		mat3 out{};

		for (int i{0}; i < 3; i++) {
			for (int j{0}; j < 3; j++) {
				out.m[i][j] =
					m[i][0] * other.m[0][j] +
					m[i][1] * other.m[1][j] +
					m[i][2] * other.m[2][j];
			}
		}

		return out;
	}

	static mat3 identity() {
		mat3 m{};

		m.m[0][0] = 1;
		m.m[1][1] = 1;
		m.m[2][2] = 1;

		return m;
	}

	static mat3 translation(float tx, float ty) {
		mat3 m{ identity() };

		m.m[0][2] = tx;
		m.m[1][2] = ty;

		return m;
	}

	static mat3 scale(float sx, float sy) {
		mat3 m{ identity() };

		m.m[0][0] = sx;
		m.m[1][1] = sy;

		return m;
	}

	static mat3 rotation(float angle) {
		mat3 m{ identity() };

		m.m[0][0] = std::cos(angle);
		m.m[1][1] = std::cos(angle);

		m.m[0][1] = std::sin(angle) * -1;
		m.m[1][0] = std::sin(angle);

		return m;
	}
};