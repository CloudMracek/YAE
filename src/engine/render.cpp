#include "render.h"

Scene activeScene = NULL;

void engineLoop(GLFWwindow *window)
{

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint programID = LoadShaders("shaders/vertexshader.glsl", "shaders/fragmentshader.glsl");
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint TextureID = glGetUniformLocation(programID, "textureSampler");

	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0));

	glm::mat4 Model = glm::mat4(1.0f);

	glm::mat4 MVP = Projection * View * Model;

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		glActiveTexture(GL_TEXTURE0);

		for (GameObject *object : activeScene.getGameObjects())
		{
			GLuint texture = object->getMesh()->getTexture()->getTextureID();
			glBindTexture(GL_TEXTURE_2D, texture);
			glUniform1i(TextureID, 0);
			object->render();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			 glfwWindowShouldClose(window) == 0);

	for (GameObject *object : activeScene.getGameObjects())
	{
		GLuint vertexBuffer = object->getMesh()->getVertexBuffer();
		glDeleteBuffers(1, &vertexBuffer);
	}
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void loadScene(Scene &scene)
{
	activeScene = scene;
}
