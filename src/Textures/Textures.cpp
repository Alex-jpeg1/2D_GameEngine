#include "Textures.hpp"

using ImageWidth = int;
using ImageHeight = int;
using ImageChannels = int;

using Data_CStyle = unsigned char *;

Texture::Texture(const std::string& fileName)
{
    ImageWidth width;
    ImageHeight height;
    ImageChannels channels;

    Data_CStyle Data = stbi_load(fileName.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    glCreateTextures(GL_TEXTURE_2D, 1, &_ID);
    glBindTexture(GL_TEXTURE_2D, _ID);

    glTexImage2D(GL_TEXTURE_2D, 0,
                 GL_RGBA, width, height,
                 0, GL_RGBA,GL_UNSIGNED_BYTE, Data 
                );

    stbi_image_free(Data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
Texture::~Texture()
{
    glDeleteTextures(1, &_ID);
}
EmptyReturn Texture::Load()
{
    glBindTexture(GL_TEXTURE_2D, _ID);
}