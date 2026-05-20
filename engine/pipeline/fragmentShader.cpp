#include "fragmentShader.hpp"

Color SinFragmentShader::process(const fragment& frag, const pipelineContext& ctx)
{
    float wave = 0.5f + 0.5f * std::sin(frag.position.x * 0.1f + ctx.time * 15.0f);

    Color out;
    out.r = frag.color.r * wave;
    out.g = frag.color.g * wave;
    out.b = frag.color.b;
    out.a = frag.color.a;
    return out;
}
