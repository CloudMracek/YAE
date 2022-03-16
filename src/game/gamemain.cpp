#include "gamemain.h"

Mesh* mesh1;
Mesh* mesh2;
GameObject* object1;
GameObject* object2;
Material* texture1;
Material* texture2;
Font* font;
Text* text;

float i = 0;
float fpsSlower = 0;

void gameSetup() {

	mesh1 = new Mesh("assets/models/cube.obj");
	mesh2 = new Mesh("assets/models/floor.obj");

    texture1 = new Material("assets/textures/cube.bmp", "assets/textures/normal.bmp");
	texture2 = new Material("assets/textures/uvtemplate.bmp");

    mesh1->setMaterial(texture1);
	mesh2->setMaterial(texture2);

	object1 =  new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
	object1->setMesh(mesh1);

	object2 =  new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
	object2->setMesh(mesh2);

	Scene scene1 = Scene("Test scene");
	scene1.addObject(object1);
	scene1.addObject(object2);

	font = new Font("assets/fonts/arial.ttf", 48);
	text = new Text("Cus", font, glm::vec2(1.0f, 48.0f), glm::vec3(1.0f), 0.25f);

	loadScene(scene1);	
}

void gameCleanup() {
    delete object1;
	delete object2;
    delete mesh1;
	delete mesh2;
	delete texture1;
	delete texture2;
	delete text;
	delete font;
}

void gameTick(float deltaTime, GLFWwindow* window) {
	
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	text->setPosition(glm::vec2(1.0f, (height/2)+55.0f));

	if (fpsSlower == 10) {
		text->setText(std::to_string((int)(1 / deltaTime)) + " FPS");
		fpsSlower = 0;
	}
	object1->setPosition(glm::vec3(0.0f, sin(i)+2.5f, 0.0f));
	object1->setRotation(glm::vec3(i, i, 0.0f));
	i = i + (0.5*deltaTime);
	fpsSlower++;
}
