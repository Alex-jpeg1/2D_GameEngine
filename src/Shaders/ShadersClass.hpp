#pragma once

#include "../../glad/glad.h"

#include <cerrno>
#include <string>
#include "../resources/resources.hpp"

std::string GetFileContent(const std::string& file);    

namespace GetShaderType
{
    enum class TileType
    {
        Air,
        UngrassedGround,
        GrassedGround,
        Stone,
        Leaf,
        TreeStem,
        Player,
    };
    class AllocateShaders
    {
        public:

        private:

    };
}

using ShaderCodeType = const char *;
using ShaderType = int;
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

    ~Shader() = default;
    //rule of 5 applied

    private:
    EmptyReturn CreateShader(GLuint&, ShaderCodeType, ShaderType);

    GLuint _ID;
};