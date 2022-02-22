#include "scene.h"

Scene::Scene(const char* sceneName) {

}

void Scene::addObject(GameObject& object) {
	_gameObjects.push_back(object);
}

std::vector<std::reference_wrapper<GameObject>> Scene::getGameObjects() {
	return _gameObjects;
}
