#include "render.h"

void engineLoop(GLFWwindow* window) {

	gameTick();

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		glClear( GL_COLOR_BUFFER_BIT );
    		glfwSwapBuffers(window);
    		glfwPollEvents();
	}
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
       glfwWindowShouldClose(window) == 0 );
}
