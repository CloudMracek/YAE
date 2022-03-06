#pragma once

#include <vector>
#include <functional>

#include <glm/glm.hpp>

#include "mesh.h"

class GameObject {
	public:
		GameObject(glm::vec3 position);
		
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();

		void setPosition(glm::vec3 position);
		void setRotation(glm::vec3 position);
		void setScale(glm::vec3 position);

		Mesh* getMesh();
		void setMesh(Mesh* mesh);

		void render();
	
	private:
		glm::vec3 _position;
		glm::vec3 _rotation;
		glm::vec3 _scale;
		Mesh* _mesh;

};;
