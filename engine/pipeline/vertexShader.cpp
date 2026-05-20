#include "vertexShader.hpp"

vertexOut SinVertexShader::process(const vertex& v, const pipelineContext& ctx)
{
    float newY = v.position.y + std::sin(ctx.time - v.position.x * 5.0f) * 0.25f;

    vertexOut out;
    out.color = v.color;
    out.position.x = v.position.x;
    out.position.y = newY;
    out.position.z = 0;
    out.position.w = 1;

    return out;
}
