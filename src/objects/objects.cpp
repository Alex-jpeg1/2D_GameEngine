#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "objects.hpp"
#include "../resources/resources.hpp"

BasicObject::BasicObject::BasicObject(double _CenterX, double _CenterY):CenterX{_CenterX},
                                                                        CenterY{_CenterY}
{}

void BasicObject::BasicObject::UpdateCenter(double _UpdateX, double _UpdateY)
{
    CenterX += _UpdateX;
    CenterY += _UpdateY;
}

Player::Player::Player():headPart{DEFAULT_CENTERX, DEFAULT_CENTERY + DEVIATION, DEFAULT_RADIUS, 50},
                         bodyPart{DEFAULT_CENTERX,DEFAULT_CENTERY,DEFAULT_HEIGHT,DEFAULT_WIDTH}
{
}

HitBox::HalfCircle::HalfCircle(double _CenterX, double _CenterY, double _radius, int _NumberVertices): 
                                                                                BasicObject::BasicObject{_CenterX,_CenterY},
                                                                                radius{_radius},
                                                                                NumberVertices{_NumberVertices}{}

void HitBox::HalfCircle::render() const
{
    glBegin(GL_TRIANGLE_FAN);

    for(int i{0}; i<=NumberVertices; i++)
    {
        double angle = PI * (static_cast<double>(i) / static_cast<double>(NumberVertices));
        float x = CenterX + radius*cos(angle);
        float y = CenterY + radius*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
}

HitBox::Square::Square(double _CenterX, double _CenterY, double _Height, double _Width):
                                                                                        BasicObject::BasicObject{_CenterX, _CenterY},
                                                                                        Height{_Height},
                                                                                        Width{_Width}{}

void HitBox::Square::render() const
{
    glBegin(GL_TRIANGLES);

    double HalfHeight = Height/2;
    double HalfWidth = Width/2;

    float YUp = CenterY + HalfHeight;
    float YDown = CenterY - HalfHeight;
    float XRight = CenterX + HalfWidth;
    float XLeft = CenterX - HalfWidth;

    glVertex2f(XRight, YUp);
    glVertex2f(XRight,  YDown);
    glVertex2f(XLeft, YDown);

    glVertex2f(XRight, YUp);
    glVertex2f(XLeft, YDown);
    glVertex2f(XLeft, YUp);

    glEnd();
}