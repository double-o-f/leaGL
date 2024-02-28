#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
//#include <stdint.h>
#include <stdbool.h>
//#include <math.h>
//#include <unistd.h>  //sleep
//#include <pthread.h>
#include "shadercomp.h"
#include "windowinit.h"
#include "tri.h"

#define SCREEN_WIDTH 800//1440//
#define SCREEN_HEIGHT 600//1080//

bool run = true;


int main(int argc, char** argv)
{
    printf("%s\n","work");

    GLFWwindow* window = WIwindowInit(SCREEN_WIDTH, SCREEN_HEIGHT);

    unsigned int basicShaderProgram = SCbasicShader();
    glUseProgram(basicShaderProgram);//use shader program when rendering an object

    unsigned int triVAO;
    unsigned int triVBO;
    TRverts(&triVAO, &triVBO);

/*
    FLOAT VERTS[] = {
        -0.5F, -0.5F, 0.0F,
        0.5F, -0.5F, 0.0F,
        0.0F, 0.5F, -1.0F,

        -0.25F, -0.25F, 0.0F,
        0.75F, -0.25F, 0.0F,
        0.25F, 0.75F, 0.0F
    };*/



//--main loop--
	run = true;
    while(run)
    {

        if (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE))
        {
                run = false;
        }

        //verts[0] += 0.01;
        //glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);

        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwWaitEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;

}
