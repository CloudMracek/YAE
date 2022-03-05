#include "render.h"

Scene activeScene = NULL;

void engineLoop(GLFWwindow* window) {

	GLuint programID = LoadShaders("shaders/vertexshader.glsl", "shaders/fragmentshader.glsl");

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		gameTick();
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glUseProgram(programID);
		for(GameObject object : activeScene.getGameObjects()) {
			object.render();
		}

    		glfwSwapBuffers(window);
    		glfwPollEvents();
	}
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
       glfwWindowShouldClose(window) == 0 );
}

void loadScene(Scene& scene) {
	activeScene = scene;
}
