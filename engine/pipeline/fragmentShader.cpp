#include "fragmentShader.hpp"

Color SinFragmentShader::process(const fragment& frag, const pipelineContext& ctx)
{
    float wave = 0.5f + 0.5f * std::sin(frag.position.x * 0.1f + ctx.time * 15.0f);

    Color out;
    out.r = frag.uv.x;
    out.g = frag.uv.y;
    out.b = 0.0f;
    out.a = 1.0f;
    return out;
}
