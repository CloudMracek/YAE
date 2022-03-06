#include "mesh.h"

void Mesh::setVertexBuffer(GLuint vertexBuffer, GLuint vxCount, GLuint uvBuffer)
{
	_vertexCount = vxCount;
	_vertexBuffer = vertexBuffer;
	_uvBuffer = uvBuffer;
}

GLuint Mesh::getVertexCount()
{
	return _vertexCount;
}

GLuint Mesh::getVertexBuffer()
{
	return _vertexBuffer;
}

GLuint Mesh::getUvBuffer()
{
	return _uvBuffer;
}

Texture* Mesh::getTexture()
{
	return _texture;
}

void Mesh::setTexture(Texture *texture)
{
	_texture = texture;
}
