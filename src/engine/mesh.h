#pragma once

#include <vector>
#include <GL/glew.h>

class Mesh {
	public:
		void setVertexBuffer(GLuint vertexBuffer, GLuint vertexCount);
		GLuint getVertexBuffer();
		GLuint vertexCount;
	private:
		GLuint _vertexBuffer;
};

