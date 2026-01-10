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

    FILE* f = fopen(fileName.c_str(), "rb"); 
    Data_CStyle Data = stbi_load_from_file(f, &width, &height, &channels, STBI_rgb_alpha);

    glCreateTextures(GL_TEXTURE_2D, 1, &_ID);
    glBindTexture(GL_TEXTURE_2D, _ID);

    glTexImage2D(GL_TEXTURE_2D, 0,
                 GL_RGBA, width, height,
                 0, GL_RGBA,GL_UNSIGNED_BYTE, Data 
                );

    stbi_image_free(Data);
}
Texture::~Texture()
{
    glDeleteTextures(1, &_ID);
}
EmptyReturn Texture::Load()
{
    glBindTexture(GL_TEXTURE_2D, _ID);
}