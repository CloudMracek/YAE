#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "../game/gamemain.h"
#include "scene.h"
#include "shaderloader.h"

extern Scene activeScene;

void engineLoop(GLFWwindow* window); 
void loadScene(Scene& scene);
