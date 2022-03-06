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

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 

	do
	{

		gameTick();
		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
		glm::mat4 View = glm::lookAt(
			glm::vec3(4, 3, 3),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0));

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

		glActiveTexture(GL_TEXTURE0);

		for (GameObject *object : activeScene.getGameObjects())
		{
			glm::mat4 translate = glm::translate(glm::mat4(1.0f), object->getPosition());
			//glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), 90.0f, object->getRotation());
			//glm::mat4 scale = glm::scale(glm::mat4(1.0f), object->getScale());
			glm::mat4 Model = translate;
			glm::mat4 MVP = Projection * View * Model;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

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
