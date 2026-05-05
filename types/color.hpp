#pragma once
#include <cstdint>

struct Color {
	float r;
	float g;
	float b;
	float a;

	Color() : r(), g(), b(), a()
	{
	
	};

	Color(float red, float green, float blue, float alpha = 1.0f) : r(red), g(green), b(blue), a(alpha)
	{

	};

	Color operator+(const Color& other) const {
		r + other.r;
		g + other.g;
		b + other.b;
		a + other.a;
	}

	Color operator*(float scalar) const {
		r * scalar;
		g * scalar;
		b * scalar;
		a * scalar;
	}

	uint32_t toRGBA() const {
		uint8_t R = static_cast<uint8_t>(r * 255.0f);
		uint8_t G = static_cast<uint8_t>(g * 255.0f);
		uint8_t B = static_cast<uint8_t>(b * 255.0f);
		uint8_t A = static_cast<uint8_t>(a * 255.0f);
	
		return (R << 24) | (G << 16) | (B << 8) | A;
	}
};