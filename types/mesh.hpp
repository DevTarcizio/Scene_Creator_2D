#pragma once
#include <vector>
#include "vertex.hpp"

class Mesh {

public:
	Mesh(const std::vector<vertex>& v, const std::vector<uint32_t>& i) : vertices(v), indices(i) {};

	void addVertex(vertex v) {
		vertices.push_back(v);

		uint32_t i = indices.size() - 1;
		indices.push_back(i);
	}
	const std::vector<vertex>& getVertices() const {
		return vertices;
	};
	const std::vector<uint32_t>& getIndices() const {
		return indices;
	};

private:
	std::vector<vertex> vertices;
	std::vector<uint32_t> indices;
};