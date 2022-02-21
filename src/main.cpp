#include "main.h"

int main ( void ) {
	

	std::cout << "done";

	if(!glfwInit()) {
		std::cout << "Failed to init glfw.\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	window = glfwCreateWindow(1366,768, "YAE", NULL, NULL);
	
	if(window == NULL) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	glewExperimental = true;
	if(glewInit() != GLEW_OK) {
		glfwTerminate();
		return -1;
	}


}
