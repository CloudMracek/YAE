#include "main.h"

int main ( void ) {
	init();
	GLFWwindow* mainWindow = createWindow(1366, 768, "YAE");
	glfwMakeContextCurrent(mainWindow);
	if(glewInit() != GLEW_OK) {
		return -1;
	}

	engineLoop(mainWindow);

	glfwTerminate();
	return 0;
}
