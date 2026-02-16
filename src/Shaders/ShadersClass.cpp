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

EmptyReturn Shader::CreateShader(GLuint& shaderID, ShaderCodeType ShaderCode, ShaderType type)
{
    shaderID = glCreateShader(type);

    glShaderSource(shaderID, 1, &ShaderCode, NULL);
    glCompileShader(shaderID);
}

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
{
    const std::string vertexCode = GetFileContent(vertexFile);
    const std::string fragmentCode = GetFileContent(fragmentFile);

    const char * vertexSource = vertexCode.c_str();
    const char * fragmentSource = fragmentCode.c_str();

    GLuint vertexShader;
    CreateShader(vertexShader, vertexSource, GL_VERTEX_SHADER);
    
    GLuint fragmentShader;
    CreateShader(fragmentShader, fragmentSource, GL_FRAGMENT_SHADER);

    _ID = glCreateProgram();

    glAttachShader(_ID, vertexShader);
    glAttachShader(_ID, fragmentShader);

    glLinkProgram(_ID);

    glUseProgram(_ID);
    
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
int Shader::UploadProjectionMatrix(std::string MatrixName)
{
    int ID = glGetUniformLocation(_ID, MatrixName.c_str());
    return ID;
}