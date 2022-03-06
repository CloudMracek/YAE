#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

#include <GL/glew.h>

class Texture {
    public:
        Texture(char* texturePath);
        GLuint getTextureID();
    private:
        GLuint _textureID;
};