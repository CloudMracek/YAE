#pragma once

#include <math.h>
#include <string>

#include <GL/glew.h>

#include "../engine/mesh.h"
#include "../engine/gameobject.h"
#include "../engine/scene.h"
#include "../engine/render.h"

void gameSetup();
void gameTick(float deltaTime, GLFWwindow* window);
void gameCleanup();
