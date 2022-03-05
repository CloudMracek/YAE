#include "gameobject.h"

GameObject::GameObject(glm::vec3 position) {
	_position = position;	
}

void GameObject::setMesh(Mesh mesh) {
	_mesh = mesh;
}

Mesh GameObject::getMesh() {
	return _mesh;
}

void GameObject::render() {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _mesh.getVertexBuffer());
	glVertexAttribPointer(
   	0,
   	3,                  // size
   	GL_FLOAT,           // type
   	GL_FALSE,           // normalized?
   	0,                  // stride
   	(void*)0            // array buffer offset
	);
	
	glDrawArrays(GL_TRIANGLES, 0, _mesh.vertexCount); 
	glDisableVertexAttribArray(0);
}

