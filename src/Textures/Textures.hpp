#include "../extern/stb_image.h"
#include "../resources/resources.hpp"
#include <string>

class Texture
{
    public:

    Texture() = default;
    Texture(const std::string& fileName);

    ~Texture();
    EmptyReturn Load();

    private:
    GLuint _ID;
};