#pragma once

#include <glm/glm.hpp>

class GameObject {
	public:
		GameObject(glm::vec3 position);
		
		glm::vec3 getPosition();
		void setPosition(glm::vec3 position);
	private:
		glm::vec3 _position;
};
