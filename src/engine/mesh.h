#pragma once

#include <vector>
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "material.h"

class Mesh {
	public:
		Mesh(const char* modelPath);
		Mesh();
		void setVertexBuffer(GLuint vertexBuffer, const GLuint vxCount, GLuint uvBuffer);
		GLuint getVertexBuffer();
		GLuint getVertexCount();
		GLuint getUvBuffer();
		GLuint getNormalBuffer();
		GLuint getTangentBuffer();
		GLuint getBitangentBuffer();
		GLuint getElementBuffer();
		GLuint getElementBufferSize();
		
		Material* getMaterial();
		void setMaterial(Material* material);
		
	private:
		GLuint _vertexCount;
		GLuint _vertexBuffer;
		GLuint _uvBuffer;
		GLuint _normalBuffer;
		GLuint _tangentBuffer;
		GLuint _bitangentBuffer;
		GLuint _elementBuffer;
		GLuint _elementBufferSize;
		Material* _material;
};

