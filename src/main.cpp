#include "main.h"

int main ( void ) {
	init();
	GLFWwindow* mainWindow = createWindow(1920, 1080, "YAE");
	glfwMakeContextCurrent(mainWindow);
	if(glewInit() != GLEW_OK) {
		return -1;
	}	
	gameSetup();
	engineLoop(mainWindow);

	gameCleanup();
	glfwTerminate();
	return 0;
}
