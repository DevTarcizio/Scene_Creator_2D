#pragma once 
#include "../../types/vertex.hpp" 
#include "../../types/context.hpp"
#include "../../types/transform.hpp"
#include <cmath>

class VertexShader { 

public: 
	// Função virtual pura 
	virtual vertexOut process(
		const vertex& v, const pipelineContext& ctx, const Transform& t, const mat3& mvp
	) = 0; 
	virtual ~VertexShader() {}; 

};

// Shader que faz o triangulo ondular na tela!
class SinVertexShader : public VertexShader {

public:
	vertexOut process(
		const vertex& v, const pipelineContext& ctx, const Transform& t, const mat3& mvp
	) override;
};

// Shader que não aplica nenhuma transformação!
class NormalVertexShader : public VertexShader {

public:
	vertexOut process(
		const vertex& v, const pipelineContext& ctx, const Transform& t, const mat3& mvp
	) override;
};