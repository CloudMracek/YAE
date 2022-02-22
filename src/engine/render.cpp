#include "render.h"

Scene activeScene = NULL;

void engineLoop(GLFWwindow* window) {

	gameTick();

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		glClear( GL_COLOR_BUFFER_BIT );

		for(GameObject object : activeScene.getGameObjects()) {
			for(Component component : object.getComponents()) {
				component.execute();
			}
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
