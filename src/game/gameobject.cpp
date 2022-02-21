#include "gameobject.h"

GameObject::GameObject(glm::vec3 position) {
	_position = position;
}

GameObject::addComponent(Component& component) {
	_components.push_back(component);
:wq!


