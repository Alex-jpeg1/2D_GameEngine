#include "ShadersClass.hpp"
#include <fstream>
#include <iostream>
#include <cerrno>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

[[ nodiscard ]]std::string GetFileContent(const std::string & file)
{
    using FileSize = int;
    std::ifstream in(file.c_str(), std::ios::binary);

    if(in)
    {
        std::string value;
        in.seekg(0,std::ios::end); //goes to the end of the file

        FileSize size = in.tellg();
        value.resize(size);

        in.seekg(0);

        in.read(&value[0], size);
        in.close();
        return value;
    }
    throw(errno);
}

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
{
    const std::string vertexCode = GetFileContent(vertexFile);
    const std::string fragmentCode = GetFileContent(fragmentFile);

    const char * vertexSource = vertexCode.c_str();
    const char * fragmentSource = fragmentCode.c_str();

    //Creating the vertexShader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    
    //Creating the fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    _ID = glCreateProgram();

    glAttachShader(_ID, vertexShader);
    glAttachShader(_ID, fragmentShader);

    glLinkProgram(_ID);

    glUseProgram(_ID);

    glm::mat4 projection = glm::ortho(0.0f, CUSTOM_DefaultWidth * 1.0f, 0.0f, CUSTOM_DefaultHeight * 1.0f, -1.0f, 1.0f);

    unsigned int projLoc = glGetUniformLocation(_ID, "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

EmptyReturn Shader::Activate()
{
    glUseProgram(_ID);
}

EmptyReturn Shader::Delete()
{
    glDeleteProgram(_ID);
}