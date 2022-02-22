#include "meshcomponent.h"

MeshComponent::MeshComponent(Mesh mesh)  {
	_mesh = mesh;
}

void MeshComponent::execute() {
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
	
	glDrawArrays(GL_TRIANGLES, 0, _mesh.getVertexCount()); 
	glDisableVertexAttribArray(0);
}

Mesh MeshComponent::getMesh() {
	return _mesh;
}

void MeshComponent::setMesh(Mesh mesh) {
	_mesh = mesh;
}
