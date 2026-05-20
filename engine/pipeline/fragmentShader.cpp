#include "fragmentShader.hpp"

Color basicFragmentShader::process(const fragment& frag) {
    Color out;
    out = frag.color;
    return out;
}

Color sinFragmentShader::process(const fragment& frag)
{
    float t = time;

    float wave = 0.5f + 0.5f * std::sin(frag.position.x * 0.05f + t * 3.0f);

    Color out;
    out.r = frag.color.r * wave;
    out.g = frag.color.g;
    out.b = frag.color.b;
    out.a = frag.color.a;
    return out;
}
