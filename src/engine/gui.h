#pragma once

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H  

#include "shaderloader.h"

struct Character {
	GLuint     TextureID;  // ID handle of the glyph texture
	glm::ivec2 Size;       // Size of glyph
	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
	GLuint     Advance;    // Offset to advance to next glyph
};

class Font {
	public:
		Font(char* path, int fontSize);
		~Font();
		GLuint getVBO();
		std::map<GLchar, Character> getCharacterMap();
	private:
		GLuint _vbo;
		std::map<GLchar, Character> _characters;
};

class Text {
	public:
		Text(std::string text, Font* font, glm::vec2 position, glm::vec3 color, float scale);
		void setText(std::string text);
		std::string getText();

		void setFont(Font* font);
		Font* getFont();

		void setPosition(glm::vec2 position);
		glm::vec2 getPosition();

		void setColor(glm::vec3 color);

		glm::vec3 getColor();

		void setScale(float scale);

		float getScale();
		
		bool getVisible();

		void show();
		void hide();
	private:
		std::string _text;
		Font* _font;
		glm::vec2 _position;
		glm::vec3 _color;
		float _scale;
		bool _visible = true;
};


void initGUI();
void renderGUI();
void cleanupGUI();
