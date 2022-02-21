#include "init.h"

bool init() {
	
	if(!glfwInit()) {
		std::cout << "Failed to init glfw.\n";
		return false;
	}

	return true;

}
