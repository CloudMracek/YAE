#include "controls.h"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix()
{
    return ViewMatrix;
}

// Initial position : on +Z
glm::vec3 position = glm::vec3(8, 5, 8);
// Initial horizontal angle : toward -Z
float horizontalAngle = 1.17f;
// Initial vertical angle : none
float verticalAngle = -1.25f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.002f;

int width, height;

void computeMatricesFromInputs(GLFWwindow *window)
{

    int focused = glfwGetWindowAttrib(window, GLFW_FOCUSED);

    glfwGetWindowSize(window, &width, &height);
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    glfwSetCursorPos(window, width / 2, height / 2);

    if (focused == 1) {
        horizontalAngle += mouseSpeed * float(width / 2 - xpos);
        verticalAngle += mouseSpeed * float(height / 2 - ypos);
    }

    if(verticalAngle > 1.5) {verticalAngle = 1.5;}
    if(verticalAngle < -1.5) {verticalAngle = -1.5;}

    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle));

    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - 3.14f / 2.0f),
        0,
        cos(horizontalAngle - 3.14f / 2.0f));

    glm::vec3 up = glm::cross(right, direction);

    if (focused == 1) {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            position += direction * deltaTime * speed;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            position -= direction * deltaTime * speed;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            position += right * deltaTime * speed;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            position -= right * deltaTime * speed;
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            position += up * deltaTime * speed;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            position -= up * deltaTime * speed;
        }
    }

    ViewMatrix = glm::lookAt(
        position,             // Camera is here
        position + direction, // and looks here : at the same position, plus "direction"
        up                    // Head is up (set to 0,-1,0 to look upside-down)
    );

    lastTime = currentTime;
}