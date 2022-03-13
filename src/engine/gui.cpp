#include "gui.h"

GLuint fontProgram;
GLuint buffer;
FT_Library ft;
GLuint vao;
std::vector<Text*> activeText;

Text::Text(std::string text, Font* font, glm::vec2 position, glm::vec3 color,float sizeMultiple) {
	_text = text;
	_font = font;
	_position = position;
	_scale = sizeMultiple;
	_color = color;
	activeText.push_back(this);
}

Font::~Font() {
	GLuint vbo = this->getVBO();
	glDeleteBuffers(1, &vbo);
}

std::string Text::getText() {
	return _text;
}

void Text::setText(std::string text) {
	_text = text;
}

Font* Text::getFont() {
	return _font;
}

void Text::setFont(Font* font) {
	_font = font;
}

bool Text::getVisible() {
	return _visible;
}

void Text::setColor(glm::vec3 color) {
	_color = color;
}

glm::vec3 Text::getColor() {
	return _color;
}

void Text::setPosition(glm::vec2 position) {
	_position = position;
}

glm::vec2 Text::getPosition() {
	return _position;
}

void Text::setScale(float scale) {
	_scale = scale;
}

float Text::getScale() {
	return _scale;
}

void Text::show() {
	_visible = true;
}

void Text::hide() {
	_visible = false;
}

void initGUI() {
	fontProgram = LoadShaders("assets/shaders/font_vertexshader.glsl", "assets/shaders/font_fragmentshader.glsl");
	glUseProgram(fontProgram);
	FT_Init_FreeType(&ft);

	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

GLuint Font::getVBO() {
	return _vbo;
}

std::map<GLchar, Character> Font::getCharacterMap() {
	return _characters;
}

Font::Font(char* path, int fontSize) {
	FT_Face face;
	FT_New_Face(ft, path, 0, &face);
	FT_Set_Pixel_Sizes(face, 0, fontSize);

	std::map<GLchar, Character> Characters;

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (GLubyte c = 0; c < 128; c++) {
		FT_Load_Char(face, c, FT_LOAD_RENDER);

		GLuint texture;
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);
		glTextureStorage2D(texture, 1, GL_R8, face->glyph->bitmap.width, face->glyph->bitmap.rows);
		glTextureSubImage2D(texture, 0, 0, 0, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		Character character = {
		texture,
		glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
		glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
		face->glyph->advance.x
		};
		Characters.insert(std::pair<GLchar, Character>(c, character));
	}

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
	glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(projection));



	glCreateBuffers(1, &buffer);

	glNamedBufferStorage(buffer, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_STORAGE_BIT);
	glVertexArrayVertexBuffer(vao, 0, buffer, 0, sizeof(GLfloat) * 4);
	glVertexArrayAttribFormat(vao, 0, 4, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(vao, 0, 0);
	glEnableVertexArrayAttrib(vao, 0);

	_vbo = buffer;
	_characters = Characters;
}

void renderText(Font* font, std::string text, glm::vec2 position, glm::vec3 color,float size) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(vao);
	glUseProgram(fontProgram);
	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
	glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(projection));

	glUniform3f(6, color.x, color.y, color.z);

	GLfloat x = position.x;
	GLfloat y = position.y;
	GLfloat scale = size;

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++) {
		Character ch = font->getCharacterMap()[*c];
		GLfloat xpos = x + ch.Bearing.x * scale;
		GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		GLfloat w = ch.Size.x * scale;
		GLfloat h = ch.Size.y * scale;
		GLfloat vertices[6 * 4] = {
			 xpos,     ypos + h,   0.0f, 0.0f ,
			 xpos,     ypos,       0.0f, 1.0f ,
			 xpos + w, ypos,       1.0f, 1.0f ,

			 xpos,     ypos + h,   0.0f, 0.0f ,
			 xpos + w, ypos,       1.0f, 1.0f ,
			 xpos + w, ypos + h,   1.0f, 0.0f
		};

		glNamedBufferSubData(buffer, 0, sizeof(GLfloat) * 6 * 4, vertices);
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		x += (ch.Advance >> 6) * scale;

	}
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
}


void renderGUI() {
	for each (Text* text in activeText)
	{
		if (text->getVisible()) {
			renderText(text->getFont(), text->getText(), text->getPosition(), text->getColor(), text->getScale());
		}
	}
}


void cleanupGUI() {
	glDeleteProgram(fontProgram);
	glDeleteVertexArrays(1, &vao);
}