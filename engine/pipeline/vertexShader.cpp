#include "vertexShader.hpp"
#include <iostream>

/*
    Local Space
        ↓
    Model Transform
        ↓
    World Space
        ↓
    View Space
        ↓
    Projection
        ↓
    NDC Space
*/

vertexOut SinVertexShader::process(const vertex& v, const pipelineContext& ctx, const Transform& t, const mat3& mvp)
{

    const Camera& c = *ctx.camera;
    vertex localVertex{};

    float newY = v.position.y + std::sin(ctx.time - (v.position.x + t.position.x) * 5.0f) * 0.25f;
    
    localVertex.position.x = v.position.x;
    localVertex.position.y = newY;

    // Vertices Locais
    vec3f LocalPosition = { localVertex.position.x, localVertex.position.y, 1.0f };

    // Uso da Model View Projection Matrix calculado no renderer::draw
    vec3f finalPosition = mvp * LocalPosition;

    vertexOut out;
    out.color = v.color;
    out.position.x = finalPosition.x;
    out.position.y = finalPosition.y;
    out.position.z = 0;
    out.position.w = 1;
    out.uv = v.uv;

    return out;
}
