#pragma once

#include "../resources/resources.hpp"
#include <glm/glm.hpp>
#include "../objects/Vector2D.hpp"

namespace Alex
{

class GravityComponent
{
    public:
        GravityComponent(){};
        GravityComponent(bool, Vector2DCustom::vect2d);
        EmptyReturn UpdateVelocity(GLfloat);
        EmptyReturn GroundedObject();


    private:
        GLfloat _velocity;
        //const GLfloat _gravitationalAcceleration;
};

}