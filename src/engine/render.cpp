#include "render.h"

Scene activeScene = NULL;

void engineLoop(GLFWwindow *window)
{

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.443f, 0.737f, 0.882f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint programID = LoadShaders("assets/shaders/vertexshader.glsl", "assets/shaders/fragmentshader.glsl");

	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
	GLuint ModelMatrixID = glGetUniformLocation(programID, "M");
	GLuint ModelView3x3MatrixID = glGetUniformLocation(programID, "MV3x3");

	GLuint DiffuseTextureID = glGetUniformLocation(programID, "DiffuseTextureSampler");
	GLuint NormalTextureID = glGetUniformLocation(programID, "NormalTextureSampler");
	GLuint UsesNormalMap = glGetUniformLocation(programID, "UsesNormalMap");

	GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	int width, height;
	double lastTime = 0;


	do
	{
		glBindVertexArray(VertexArrayID);
		double currentTime = glfwGetTime();
		float deltaTime = float(currentTime - lastTime);
		lastTime = currentTime;

		gameTick(deltaTime, window);
		glfwGetWindowSize(window, &width, &height);

		computeMatricesFromInputs(window);
		glm::mat4 Projection = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 100.0f);
		glm::mat4 View = getViewMatrix();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);
		glm::vec3 lightPos = glm::vec3(5, 15, 0);
		glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
		glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);

		glActiveTexture(GL_TEXTURE0);

		for (GameObject *object : activeScene.getGameObjects())
		{
			glm::mat4 translate = glm::translate(glm::mat4(1.0f), object->getPosition());
			glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), object->getRotation()[0], glm::vec3(1.0f, 0.0f, 0.0f));
			rotate = glm::rotate(glm::mat4(1.0f), object->getRotation()[1], glm::vec3(0.0f, 1.0f, 0.0f)) * rotate;
			rotate = glm::rotate(glm::mat4(1.0f), object->getRotation()[2], glm::vec3(0.0f, 0.0f, 1.0f)) * rotate;

			glm::mat4 scale = glm::scale(glm::mat4(1.0f), object->getScale());
			glm::mat4 Model = translate * scale * rotate;
			glm::mat3 ModelView3x3Matrix = glm::mat3(Model);
			glm::mat4 MVP = Projection * View * Model;

			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
			glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Model[0][0]);
			glUniformMatrix3fv(ModelView3x3MatrixID, 1, GL_FALSE, &ModelView3x3Matrix[0][0]);

			GLuint DiffuseTexture = object->getMesh()->getMaterial()->getDiffuseTextureID();
			GLuint NormalTexture = object->getMesh()->getMaterial()->getNormalTextureID();

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, DiffuseTexture);
			// Set our "DiffuseTextureSampler" sampler to use Texture Unit 0
			glUniform1i(DiffuseTextureID, 0);


			if (NormalTexture != 9999) {
				glActiveTexture(GL_TEXTURE1);
				glBindTexture(GL_TEXTURE_2D, NormalTexture);
				// Set our "NormalTextureSampler" sampler to use Texture Unit 1
				glUniform1i(UsesNormalMap, 1);
			}
			else {
				glUniform1i(UsesNormalMap, 0);
			}
			glUniform1i(NormalTextureID, 1);


			object->render();
		}
		renderGUI();
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			 glfwWindowShouldClose(window) == 0);

	for (GameObject *object : activeScene.getGameObjects())
	{
		GLuint vertexBuffer = object->getMesh()->getVertexBuffer();
		GLuint uvBuffer = object->getMesh()->getUvBuffer();
		GLuint normalBuffer = object->getMesh()->getNormalBuffer();
		GLuint elementBuffer = object->getMesh()->getElementBuffer();
		glDeleteBuffers(1, &uvBuffer);
		glDeleteBuffers(1, &vertexBuffer);
		glDeleteBuffers(1, &normalBuffer);
		glDeleteBuffers(1, &elementBuffer);
	}
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void loadScene(Scene &scene)
{
	activeScene = scene;
}
