#include "mesh.h"

void Mesh::setVertexBuffer(GLuint vertexBuffer, GLuint vxCount) {
	_vertexBuffer = vertexBuffer;
	vertexCount = vxCount;
}

GLuint Mesh::getVertexBuffer() {
	return _vertexBuffer;
}


