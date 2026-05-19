#pragma once
#include "types/vertex.hpp"

class VertexShader {

public:

	// Função virtual pura
	virtual vertexOut process(const vertex& v) = 0;

	virtual ~VertexShader() {};
};

class BasicShader : public VertexShader {
public:
	vertexOut process(const vertex& v) override;
};