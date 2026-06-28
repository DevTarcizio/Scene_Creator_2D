#include "object.hpp"

Object::Object(Mesh* m, const Transform& t, Texture* texture) : mesh(m), transform(t), tex(texture) {

}

void Object::setVertexShader(VertexShader* vs)
{
	vertexShader = vs;
}

void Object::setFragmentShader(FragmentShader* fs)
{
	fragmentShader = fs;
}

Mesh* Object::getMesh() const
{
	return mesh;
}

Transform& Object::getTransform()
{
	return transform;
}

const Transform& Object::getTransform() const
{
	return transform;
}

VertexShader* Object::getVertexShader() const
{
	return vertexShader;
}
 
FragmentShader* Object::getFragmentShader() const
{
	return fragmentShader;
}

Texture* Object::getTexture() const
{
	return tex;
}

