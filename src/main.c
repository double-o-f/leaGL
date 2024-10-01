#include "glad/glad.h"
#include <GLFW/glfw3.h>

// include <stdlib.h>
#include <stdio.h>
// #include <stdint.h>
#include <stdbool.h>
// #include <math.h>
// #include <unistd.h>  //sleep
// #include <pthread.h>
#include "shadercomp.h"
#include "tri.h"
#include "windowinit.h"

#define SCREEN_WIDTH 800  // 1440//
#define SCREEN_HEIGHT 600 // 1080//

bool run = true;

int main(int argc, char **argv) {
    printf("%s\n", "init");

    GLFWwindow *window = WI_windowInit(SCREEN_WIDTH, SCREEN_HEIGHT);

    unsigned int basicShaderProgram = SC_basicShader();
    glUseProgram(basicShaderProgram); // use shader program when rendering an object

    unsigned int triVAO;
    unsigned int triVBO;
    TR_verts(&triVAO, &triVBO);

    //--main loop--
    run = true;
    while (run) {

        if (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            run = false;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwWaitEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
