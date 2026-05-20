#pragma once
#include "../../types/fragment.hpp"
#include "../../types/context.hpp"
#include <cmath>

class FragmentShader {

public:
	virtual Color process(const fragment& frag, const pipelineContext& ctx) = 0;
	virtual ~FragmentShader() {};

	
};


class SinFragmentShader : public FragmentShader {
public:
	Color process(const fragment& frag, const pipelineContext& ctx) override;
};