#pragma once
#include "../../types/fragment.hpp"
#include <cmath>

class fragmentShader {

public:
	virtual Color process(const fragment& frag) = 0;
	virtual ~fragmentShader() {};

	
};

class basicFragmentShader : public fragmentShader {

public:
	Color process(const fragment& frag) override;
};

class sinFragmentShader : public fragmentShader {
public:
	Color process(const fragment& frag) override;
	float time;
};