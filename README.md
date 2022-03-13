![Logo](https://github.com/CloudMracek/YAE/blob/main/logo-white.png?raw=true)

## The basics

This engine is **not yet finished.** There are no normal maps, there is no sound, there is no controller support. The list just goes on... The engine currently supports these features:

- Create objects and manage them in scenes
- Load meshes from *.obj* files
- Load textures from either *.bmp* or *.DDS* files
- Manage the position, scale and rotation on those objects
- Draw those objects (duh)
- Does basic shading with one static unmovable light
- Draw basic 2D GUI text
- Not cause memory leaks (hopefully)

## Building
To build this you just use:
```
git clone https://github.com/CloudMracek/YAE/ --recursive
cd YAE
mkdir build
cd build
cmake ..
make
```
Or you can use cmake-gui on Windows

## Usage
You can find two folders in the source code:
- engine
- game

Don't touch the engine one. (unless you actually want to change them and you're mentally prepared to read my code) 

The "game" folder is dedicated specially for you <3 (It's where all your code goes)

## Example
Here is a short and dirty example of all the things the engine can do at the moment:
```cpp
#include "gamemain.h"

GLuint vertexBuffer;
Mesh* mesh1;
GameObject* object;
Texture* texture;
Font* font;
Text* text;

float i = 0;
int fpsSlower = 0;

void gameSetup() {
  
  // Create a mesh and load "cube.obj" into it
  mesh1 = new Mesh("models/cube.obj"); 

  // Create a texture and load "cube.bmp" into it (supports .DDS as well)
  texture = new Texture("textures/cube.bmp");
  
  // Assign the texture to the mesh
  mesh1->setTexture(texture);

  // Create a game object
  object =  new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));
  
  // Asign the mesh to the game object
  object->setMesh(mesh1);

  // Create a scene
  Scene scene1 = Scene("Test scene");
  
  // Add our game object to the scene
  scene1.addObject(object);
  
  // Load a font from file
  font = new Font("assets/fonts/LiberationSerif-Regular.ttf", 48);
  // Create a GUI text on the screen
  text = new Text("Cus", font, glm::vec2(1.0f, 48.0f), glm::vec3(1.0f), 0.5f);

  // Load our scene
  loadScene(scene1);
}

// Cleanup our mess (pointers)
void gameCleanup() {
  delete object;
  delete mesh1;
  delete texture;
  delete text;
  delete font;
}

// Called every frame
void gameTick() {

  // Write the current FPS on our screen (FPS slower is there to make it slower so it's readable)
  if (fpsSlower == 10) {
    text->setText(std::to_string((int)(1 / deltaTime)) + " FPS");
    fpsSlower = 0;
  }
  
  // Set position / rotation / scale (as you wish)
  object->setPosition(glm::vec3(0.0f, sin(i), 0.0f));
  object->setRotation(glm::vec3(i, i, 0.0f));
  i = i + 0.01f;
}
```

## TODO
(In this order of priority)
- ~~GUI~~ - Basic 2D text done
- Normal mapping
- Allow light customization
- Controller input (PS5 adaptive triggers, haptics)
- Sound

## License
Everything (including the rubik's cube model and texture - Thanks [Memmer](https://github.com/memmer57)) is licensed under the GPL-3.0 license. See [LICENSE](https://github.com/CloudMracek/YAE/blob/main/LICENSE) for more info.


## Thanks
Special thanks goes to [Kurzgesagt](https://www.youtube.com/c/inanutshell) - the channel which ignited my love for science after our school system dumped a bucket of water on it.

Thanks to [Memmer](https://github.com/memmer57) for supplying the rubik's cube model and kindly agreeing to share it under GPL-3.0
