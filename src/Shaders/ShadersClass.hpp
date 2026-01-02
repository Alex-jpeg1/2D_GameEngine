#pragma once

#include "../../glad/glad.h"
#include "GLFW/glfw3.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <string>
#include "../resources/resources.hpp"

std::string GetFileContent(const std::string& file);    

class Shader
{
    public:

    Shader() = default;

    [[ nodiscard ]] GLuint GET_ID() const { return _ID; }
    Shader(const std::string& vertexFile, const std::string& fragmentFile);

    EmptyReturn Activate();
    EmptyReturn Delete();

    Shader(const Shader& other) = default;
    Shader& operator=(const Shader& other) = default;

    Shader(Shader&& other) = default;
    Shader& operator=(Shader&& other) = default;

    ~Shader() { Delete(); }
    //rule of 5 applied

    private:

    
    GLuint _ID;
};