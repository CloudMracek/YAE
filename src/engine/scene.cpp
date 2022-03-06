#include "scene.h"

Scene::Scene(const char* sceneName) {

}

void Scene::addObject(GameObject* object) {
	_gameObjects.push_back(object);
}

std::vector<GameObject*> Scene::getGameObjects() {
	return _gameObjects;
}

GameObject* Scene::getGameObject(int i) {
	return _gameObjects[i];
}