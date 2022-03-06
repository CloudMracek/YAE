#pragma once

#include <vector>
#include <functional>

#include "gameobject.h"

class Scene {
	public:
		Scene(const char* sceneName);

		void addObject(GameObject* object);
		std::vector<GameObject*> getGameObjects();
		GameObject* getGameObject(int i);
	private:
		std::vector<GameObject*> _gameObjects;
};
