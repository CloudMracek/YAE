#include "gamemain.h"

static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

GLuint vertexBuffer;
Mesh mesh1;

void gameSetup() {
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	mesh1 = Mesh();
	mesh1.setVertexBuffer(vertexBuffer, 3);


	GameObject object = GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
	object.setMesh(mesh1);

	Scene scene1 = Scene("Test scene");
	scene1.addObject(object);

	loadScene(scene1);
}

void gameTick() {

}
