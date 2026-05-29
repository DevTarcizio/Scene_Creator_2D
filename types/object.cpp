#include "object.hpp"

Object::Object(Mesh* m, const Transform& t) : mesh(m), transform(t) {

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

VertexShader* Object::getVertexShader() const
{
	return vertexShader;
}
 
FragmentShader* Object::getFragmentShader() const
{
	return fragmentShader;
}

