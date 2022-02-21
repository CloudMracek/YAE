#include "windowmanager.h"

GLFWwindow* createWindow(GLuint width, GLuint height, const char* windowName) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	window = glfwCreateWindow(width, height, windowName, NULL, NULL);
	
	if(window == NULL) {
		glfwTerminate();
		return NULL;
	}

	return window;
}
