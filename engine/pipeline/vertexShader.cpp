#include "vertexShader.hpp"

vertexOut SinVertexShader::process(const vertex& v, const pipelineContext& ctx)
{
    vertex localVertex{};

    float newY = v.position.y + std::sin(ctx.time - (v.position.x + ctx.transform.position.x) * 5.0f) * 0.25f;
    
    localVertex.position.x = v.position.x;
    localVertex.position.y = newY;

    vec3f vertex = { localVertex.position.x, localVertex.position.y, 1 };
    mat3 matrixTransform = ctx.transform.getMatrix();
    vec3f transformedVertex = matrixTransform * vertex;

    
    vertexOut out;
    out.color = v.color;
    out.position.x = transformedVertex.x;
    out.position.y = transformedVertex.y;
    out.position.z = 0;
    out.position.w = 1;

    return out;
}
