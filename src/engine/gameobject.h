#pragma once

#include <vector>
#include <functional>

#include <glm/glm.hpp>

#include "mesh.h"

class GameObject {
	public:
		GameObject(glm::vec3 position);
		
		glm::vec3 getPosition();
		void setPosition(glm::vec3 position);
		Mesh* getMesh();
		void setMesh(Mesh* mesh);
		void render();
	
	private:
		glm::vec3 _position;
		Mesh* _mesh;

};;
