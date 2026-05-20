#pragma once 
#include "../../types/vertex.hpp" 
#include "../../types/context.hpp"
#include <cmath>

class VertexShader { 

public: 
	// Função virtual pura 
	virtual vertexOut process(const vertex& v, const pipelineContext& ctx) = 0; 
	virtual ~VertexShader() {}; 

};

// Shader que faz o triangulo ondular na tela!
class SinVertexShader : public VertexShader {

public:
	vertexOut process(const vertex& v, const pipelineContext& ctx) override;
};