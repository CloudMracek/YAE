#include "gamemain.h"

GLuint vertexBuffer;
Mesh* mesh1;
GameObject* object;
Texture* texture;

float i = 0;

void gameSetup() {

	mesh1 = new Mesh("models/cube.obj");

    texture = new Texture("textures/uvtemplate.bmp");
    mesh1->setTexture(texture);

	object =  new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
	object->setMesh(mesh1);

	Scene scene1 = Scene("Test scene");
	scene1.addObject(object);

	loadScene(scene1);
}

void gameCleanup() {
    delete object;
    delete mesh1;
	delete texture;
}

void gameTick() {
	object->setPosition(glm::vec3(0.0f, sin(i), 0.0f));
	object->setRotation(glm::vec3(i, i, 0.0f));
	i = i + 0.01f;
}
