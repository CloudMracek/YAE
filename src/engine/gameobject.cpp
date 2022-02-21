#include "gameobject.h"


GameObject::GameObject(glm::vec3 position) {
	_position = position;
	_components = std::vector<std::reference_wrapper<Component>> {};
	
}

void GameObject::addComponent(Component& component) {
	_components.push_back(std::reference_wrapper<Component>{component});
}


