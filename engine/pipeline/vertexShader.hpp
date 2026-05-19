#pragma once 
#include "../../types/vertex.hpp" 
#include <cmath>

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

// Shader que faz o triangulo ondular na tela!
class SinShader : public VertexShader {

public:
	vertexOut process(const vertex& v) override;

	float time;
};