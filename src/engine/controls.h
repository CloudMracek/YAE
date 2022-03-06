#pragma once

#include <iostream>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

void computeMatricesFromInputs(GLFWwindow* window);
glm::mat4 getViewMatrix();
