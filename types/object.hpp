#pragma once
#include "mesh.hpp"
#include "transform.hpp"
#include "../engine/pipeline/vertexShader.hpp"
#include "../engine/pipeline/fragmentShader.hpp"

class Object {
public:
	Object(Mesh* m, const Transform& t);

	void setVertexShader(VertexShader* vs);
	void setFragmentShader(FragmentShader* fs);

	Mesh* getMesh() const;
	Transform& getTransform();
	const Transform& getTransform() const;
	VertexShader* getVertexShader() const;
	FragmentShader* getFragmentShader() const;

private:
	Mesh* mesh = nullptr;
	Transform transform;
	VertexShader* vertexShader = nullptr;
	FragmentShader* fragmentShader = nullptr;
};