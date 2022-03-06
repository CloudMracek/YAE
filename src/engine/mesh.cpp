#include "mesh.h"

void Mesh::setVertexBuffer(GLuint vertexBuffer, GLuint vxCount) {
	_vertexCount = vxCount;
	_vertexBuffer = vertexBuffer;
}

GLuint Mesh::getVertexCount() {
	return _vertexCount;
}

GLuint Mesh::getVertexBuffer() {
	return _vertexBuffer;
}


