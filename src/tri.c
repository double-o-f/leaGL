#include "glad/glad.h"
#include <GLFW/glfw3.h>


void TRverts(unsigned int *VAO, unsigned int *VBO)
{

    float verts[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, -1.0f,

        -0.25f, -0.25f, 0.0f,
        0.75f, -0.25f, 0.0f,
        0.25f, 0.75f, 0.0f
    };

    glGenVertexArrays(1, VAO);

    glBindVertexArray(*VAO);

    glGenBuffers(1, VBO);

    glBindBuffer(GL_ARRAY_BUFFER, *VBO); //copy vertices array in a buffer for OpenGL to use
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),(void*)0);//set the vertex attributes pointers
    glEnableVertexAttribArray(0);

}
