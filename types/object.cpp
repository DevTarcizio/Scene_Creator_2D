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

bool Object::contains(float x, float y) const
{
	float leftBorder = transform.position.x - (transform.scale.x / 2.0f);
	float rightBorder = transform.position.x + (transform.scale.x / 2.0f);
	float bottomBorder = transform.position.y - (transform.scale.y / 2.0f);
	float topBorder = transform.position.y + (transform.scale.y / 2.0f);

	if ((x >= leftBorder && x <= rightBorder) && (y >= bottomBorder && y <= topBorder)) {
		return true;
	}

	return false;
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

