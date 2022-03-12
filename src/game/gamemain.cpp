#include "gamemain.h"

Mesh* mesh1;
Mesh* mesh2;
GameObject* object1;
GameObject* object2;
Texture* texture1;
Texture* texture2;

float i = 0;

void gameSetup() {

	mesh1 = new Mesh("assets/models/cube.obj");
	mesh2 = new Mesh("assets/models/floor.obj");

    texture1 = new Texture("assets/textures/cube.bmp");
	texture2 = new Texture("assets/textures/uvtemplate.bmp");

    mesh1->setTexture(texture1);
	mesh2->setTexture(texture2);

	object1 =  new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
	object1->setMesh(mesh1);

	object2 =  new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
	object2->setMesh(mesh2);

	Scene scene1 = Scene("Test scene");
	scene1.addObject(object1);
	scene1.addObject(object2);

	loadScene(scene1);	
}

void gameCleanup() {
    delete object1;
	delete object2;
    delete mesh1;
	delete mesh2;
	delete texture1;
	delete texture2;
}

void gameTick() {
	object1->setPosition(glm::vec3(0.0f, sin(i)+2.5f, 0.0f));
	object1->setRotation(glm::vec3(i, i, 0.0f));
	i = i + 0.01f;
}
