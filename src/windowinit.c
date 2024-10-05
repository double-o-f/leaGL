#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>


GLFWwindow* WI_windowInit(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{

    GLFWwindow* window;
    const char* infoLog;

    if (!glfwInit())
    {
        glfwGetError(&infoLog);
        printf("Error: %s\n", infoLog);
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE); // true = top of window ui
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "test_window", NULL, NULL);
    if (!window)
    {
        glfwGetError(&infoLog);
        printf("Error: %s\n", infoLog);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress))
    {
        printf("TODO\n");
        exit(EXIT_FAILURE);
    }

    //glClearColor(0.20f, 0.19f, 0.21f, 0.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    return window;

}
