#pragma once

#include <vector>
#include <functional>

#include "gameobject.h"

class Scene {
	public:
		Scene(const char* sceneName);

		void addObject(GameObject& object);
		std::vector<std::reference_wrapper<GameObject>> getGameObjects();
	private:
		std::vector<std::reference_wrapper<GameObject>> _gameObjects;
};
