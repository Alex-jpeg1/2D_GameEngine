#pragma once

#include "../resources/resources.hpp"
#include <glm/glm.hpp>
#include "../objects/Vector2D.hpp"

namespace Alex
{

class MatrixFactory
{
    public:
        MatrixFactory(Vector2DCustom::vect2d);
        EmptyReturn UpdateVelocityVector();
        
    private:
        glm::vec2 _position;
        glm::vec2 _velocity;
        glm::mat4 _modelMatrix;
};
class GravityComponent
{
    public:
        GravityComponent(bool, Vector2DCustom::vect2d);
        EmptyReturn UpdateVelocity(GLfloat);
        EmptyReturn GroundedObject();


    private:
        GLfloat _velocity;
        const GLfloat _gravitationalAcceleration;
        MatrixFactory _transMatrix;
};

}