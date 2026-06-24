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

vertexOut SinVertexShader::process(const vertex& v, const pipelineContext& ctx, const Transform& t)
{

    const Camera& c = *ctx.camera;
    vertex localVertex{};

    float newY = v.position.y + std::sin(ctx.time - (v.position.x + t.position.x) * 5.0f) * 0.25f;
    
    localVertex.position.x = v.position.x;
    localVertex.position.y = newY;

    vec3f LocalPosition = { localVertex.position.x, localVertex.position.y, 1.0f };
    mat3 matrixTransform = t.getMatrix();
    vec3f WorldPosition = matrixTransform * LocalPosition;

    float halfWidth = ( c.viewport.x / c.zoom ) * 0.5f;
    float halfHeight = (c.viewport.y / c.zoom) * 0.5f;

    vec3f ViewPosition = { WorldPosition.x - c.position.x, WorldPosition.y - c.position.y, 1.0f };
    vec3f NDCPosition = { 
        ViewPosition.x / halfWidth, 
        ViewPosition.y / halfHeight,
        1.0f
    };

    vertexOut out;
    out.color = v.color;
    out.position.x = NDCPosition.x;
    out.position.y = NDCPosition.y;
    out.position.z = 0;
    out.position.w = 1;

    return out;
}
