#pragma once
#include <vector>
#include <memory>
#include "object.hpp"

class Scene {
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual ~Scene() = default;

protected:
	std::vector<std::unique_ptr<Object>> objects;
};

class EditorScene : public Scene {
	void draw() override;
	void update() override;
	~EditorScene() override;
};