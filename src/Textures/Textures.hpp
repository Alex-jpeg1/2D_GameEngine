#pragma once
#include "../extern/stb_image.h"
#include "../resources/resources.hpp"
#include <string>

class Texture
{
    public:

    Texture() = default;
    Texture(const std::string& fileName);

    Texture(const Texture& other) = delete;
    void operator=(const Texture& other) = delete;
    ~Texture();
    EmptyReturn Load();


    private:

    GLuint _ID;
};