#include "gameobject.h"

GameObject::GameObject(glm::vec3 position) {
	_position = position;	
}

void GameObject::setMesh(Mesh* mesh) {
	_mesh = mesh;
}

Mesh* GameObject::getMesh() {
	return _mesh;
}

void GameObject::render() {
	glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, _mesh->getVertexBuffer());
		glVertexAttribPointer(
			0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, _mesh->getVertexCount()); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);
}

