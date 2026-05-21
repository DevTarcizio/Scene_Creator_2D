#include "vertexShader.hpp"

vertexOut SinVertexShader::process(const vertex& v, const pipelineContext& ctx)
{
    float newY = v.position.y + std::sin(ctx.time - (v.position.x + ctx.transform.position.x) * 5.0f) * 0.25f;

    vertexOut out;
    out.color = v.color;
    out.position.x = v.position.x;
    out.position.y = v.position.y;
    out.position.z = 0;
    out.position.w = 1;

    // Transformation
    out.position.x *= ctx.transform.scale.x;
    out.position.y *= ctx.transform.scale.y;

    float rotateX = out.position.x * std::cos(ctx.transform.rotation) - out.position.y * std::sin(ctx.transform.rotation);
    float rotateY = out.position.x * std::sin(ctx.transform.rotation) + out.position.y * std::cos(ctx.transform.rotation);

    out.position.x = rotateX;
    out.position.y = rotateY;

    out.position.x += ctx.transform.position.x;
    out.position.y += ctx.transform.position.y;

    return out;
}
