#pragma once

#include <vector>
#include <functional>

#include <glm/glm.hpp>

#include "component.h"

class GameObject {
	public:
		GameObject(glm::vec3 position);
		
		glm::vec3 getPosition();
		void setPosition(glm::vec3 position);

		std::vector<Component> getComponents();
		Component getComponent(uint id);
		void addComponent(Component& component);
		void removeComponent(uint componentID);
	
	private:
		glm::vec3 _position;
		std::vector<std::reference_wrapper<Component>> _components;

};
