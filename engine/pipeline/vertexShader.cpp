#include "vertexShader.hpp"

vertexOut BasicShader::process(const vertex& v)
{
    vertexOut out;
    out.color = v.color;
    out.position.x = v.position.x;
    out.position.y = v.position.y;
    out.position.z = 0;
    out.position.w = 1;

    return out;
}

vertexOut SinShader::process(const vertex& v)
{
    float newY = v.position.y + std::sin(time * 15.0f - v.position.x * 15.0f) * 0.25f;

    vertexOut out;
    out.color = v.color;
    out.position.x = v.position.x;
    out.position.y = newY;
    out.position.z = 0;
    out.position.w = 1;

    return out;
}
