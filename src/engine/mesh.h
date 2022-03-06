#pragma once

#include <vector>
#include <GL/glew.h>

#include "texture.h"

class Mesh {
	public:
		void setVertexBuffer(GLuint vertexBuffer, const GLuint vxCount, GLuint uvBuffer);
		GLuint getVertexBuffer();
		GLuint getVertexCount();
		GLuint getUvBuffer();
		
		Texture* getTexture();
		void setTexture(Texture* texture);
		
	private:
		GLuint _vertexCount;
		GLuint _vertexBuffer;
		GLuint _uvBuffer;
		Texture* _texture;
};

