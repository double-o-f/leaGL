#include "glad/glad.h"

#include <stdio.h>


unsigned int SC_basicShader()
{

//--vert shader--
    const char *vertexShaderSource = "#version 460 core\n"
        "layout(location = 0) in vec3 aPos;\n"
        //"in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("%s\n","ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        printf("%s\n",infoLog);
    }


//--frag shader--
    const char *fragmentShaderSource = "#version 460 core\n"
        "out vec4 FragColor;\n"
        "vec3 co = gl_FragCoord.xyz/600; \n"
        "void main()\n"
        "{\n"
        " FragColor = vec4(co.x, co.x/2, co.y, 1.0f);\n"
        "}\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("%s\n","ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        printf("%s\n",infoLog);
    }


//--set up shader--
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("%s\n","ERROR::SHADERPROG::LINK_FAILED");
        printf("%s\n",infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
