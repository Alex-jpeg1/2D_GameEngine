#pragma once

#include "../resources/resources.hpp"

namespace Alex

{
class GravityComponent
{
    public:
        EmptyReturn UpdateVelocity();
    private:
        GLfloat velocity;
        const GLfloat gravitationalAcceleration = 9.8;

};

}