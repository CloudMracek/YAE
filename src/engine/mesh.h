#pragma once

#include <vector>
#include <GL/glew.h>

class Mesh {
	public:
		void setVertexBuffer(GLuint vertexBuffer, GLuint vertexCount);
		GLuint getVertexBuffer();
		GLuint getVertexCount();
	private:
		GLuint _vertexBuffer;
		GLuint _vertexCount;
};

