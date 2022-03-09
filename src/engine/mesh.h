#pragma once

#include <vector>
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.h"

class Mesh {
	public:
		Mesh(const char* modelPath);
		Mesh();
		void setVertexBuffer(GLuint vertexBuffer, const GLuint vxCount, GLuint uvBuffer);
		GLuint getVertexBuffer();
		GLuint getVertexCount();
		GLuint getUvBuffer();
		GLuint getNormalBuffer();
		GLuint getElementBuffer();
		GLuint getElementBufferSize();
		
		Texture* getTexture();
		void setTexture(Texture* texture);
		
	private:
		GLuint _vertexCount;
		GLuint _vertexBuffer;
		GLuint _uvBuffer;
		GLuint _normalBuffer;
		GLuint _elementBuffer;
		GLuint _elementBufferSize;
		Texture* _texture;
};

