#include "renderer.hpp"

Renderer::Renderer(int w, int h) : width(w), height(h), framebuffer(w * h, 0), rasterizer(w, h)
{
}

bool Renderer::isInsideScreen(screenVertex& v) const
{
	if (v.position.x >= width || v.position.x < 0) {
		return false;
	}
	if (v.position.y >= height || v.position.y < 0) {
		return false;
	}

	return true;
}

void Renderer::setOnPixel(screenVertex& v)
{
	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = v.color.toRGBA();
}

void Renderer::setOffPixel(screenVertex& v)
{
	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = 0xFFFFFFFF;
}

void Renderer::draw(const Object& obj, pipelineContext& ctx)
{
	Mesh* m = obj.getMesh();
	Transform t = obj.getTransform();
	VertexShader* vs = obj.getVertexShader();
	FragmentShader* fs = obj.getFragmentShader();

	rasterizer.bindFragmentShader(fs);

	const auto& vertices = m->getVertices();
	const auto& indices = m->getIndices();

	for (size_t i{ 0 }; i < indices.size(); i += 3) {
		uint32_t i0 = indices[i];
		uint32_t i1 = indices[i + 1];
		uint32_t i2 = indices[i + 2];

		vertexOut out0 = vs->process(vertices[i0], ctx, t);
		vertexOut out1 = vs->process(vertices[i1], ctx, t);
		vertexOut out2 = vs->process(vertices[i2], ctx, t);

		rasterizer.drawTriangle(out0, out1, out2, *this, ctx);
	}
}

void Renderer::clear(Color color)
{
	uint32_t c = color.toRGBA();
	for (int i{ 0 }; i < framebuffer.size(); i++) {
		framebuffer[i] = c;
	}
}

uint32_t* Renderer::getFramebufferData()
{
	return framebuffer.data();
}

int Renderer::getWidth()
{
	return width;
}

int Renderer::getHeight()
{
	return height;
}
