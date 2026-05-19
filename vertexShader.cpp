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
