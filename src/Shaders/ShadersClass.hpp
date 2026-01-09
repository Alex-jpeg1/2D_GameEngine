#pragma once

#include "../../glad/glad.h"

#include <cerrno>
#include <string>
#include "../resources/resources.hpp"

std::string GetFileContent(const std::string& file);    

namespace GetShaderType
{
    class AllocateShaders
    {
        public:

        private:
        enum class TileType
        {
            _Air,
            _UngrassedGround,
            _GrassedGround,
            _Stone,
            _Leaf,
            _TreeStem,
        };
    };
}

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

    GLuint _ID;
};