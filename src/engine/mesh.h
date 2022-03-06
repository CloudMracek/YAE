#pragma once

#include <vector>
#include <GL/glew.h>

class Mesh {
	public:
		void setVertexBuffer(GLuint vertexBuffer, const GLuint vxCount);
		GLuint getVertexBuffer();
		GLuint getVertexCount();
		
	private:
		GLuint _vertexCount;
		GLuint _vertexBuffer;
};

