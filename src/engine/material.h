#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

#include <GL/glew.h>

class Material {
    public:
        Material(const char* diffuseTexturePath);
        Material(const char* diffuseTexturePath, const char* normalTexturePath);
        GLuint getDiffuseTextureID();
        GLuint getNormalTextureID();
    private:
        GLuint _diffuseTextureID;
        GLuint _normalTextureID;
};