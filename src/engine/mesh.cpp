#include "mesh.h"

void Mesh::setVertexBuffer(GLuint vertexBuffer, GLuint vertexCount) {
	_vertexBuffer = vertexBuffer;
	_vertexCount = vertexCount;
}

GLuint Mesh::getVertexBuffer() {
	return _vertexBuffer;
}

GLuint Mesh::getVertexCount() {
	return _vertexCount;
}

