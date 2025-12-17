#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "objects.hpp"

BasicObject::BasicObject::BasicObject(long double _CenterX, long double _CenterY, long double _Height, long double _Width):CenterX{_CenterX},
                                                                                                                           CenterY{_CenterY},
                                                                                                                           Height{_Height},
                                                                                                                           Width{_Width}
{}

void BasicObject::BasicObject::UpdateCenter(long double _UpdateX, long double _UpdateY)
{
    CenterX += _UpdateX;
    CenterY += _UpdateY;
}

void BasicObject::BasicObject::OverWriteCenter(long double _UpdateX, long double _UpdateY)
{
    CenterX = _UpdateX;
    CenterY = _UpdateY;
}

HitBox::HalfCircle::HalfCircle(long double _CenterX, long double _CenterY, long double _radius, int _NumberVertices): 
                                                                                BasicObject::BasicObject{_CenterX,_CenterY,_radius,_radius},
                                                                                NumberVertices{_NumberVertices}{}

void HitBox::HalfCircle::render() const
{
    glBegin(GL_TRIANGLE_FAN);

    for(int i{0}; i<=NumberVertices; i++)
    {
        long double angle = PI * (static_cast<long double>(i) / static_cast<long double>(NumberVertices));
        float x = CenterX + Height*cos(angle);
        float y = CenterY + Height*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
}

HitBox::Square::Square(long double _CenterX, long double _CenterY, long double _Height, long double _Width):BasicObject::BasicObject{_CenterX, 
                                                                                                                                     _CenterY,
                                                                                                                                      _Height,
                                                                                                                                       _Width}
{}
void HitBox::Square::render() const 
{
    glBegin(GL_TRIANGLES);
    long double HalfHeight = Height/2;
    long double HalfWidth = Width/2;

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
long double BasicObject::BasicObject::ReturnPositionY() const 
{
    return CenterY;
}
long double BasicObject::BasicObject::ReturnHeight() const 
{
    return Height;
}
long double BasicObject::BasicObject::ReturnTop()const 
{
    return (ReturnPositionY() + ReturnHeight() / 2);
}
long double BasicObject::BasicObject::ReturnPositionX() const
{
    return CenterX;
}
long double BasicObject::BasicObject::ReturnWidth() const 
{
    return Width;
}
long double BasicObject::BasicObject::ReturnLeft() const
{
    return (ReturnPositionX() - ReturnWidth() / 2);
}
long double BasicObject::BasicObject::ReturnRight() const
{
    return (ReturnPositionX() + ReturnWidth() / 2);
}
long double BasicObject::BasicObject::ReturnBottom() const
{
    return CenterY - Height / 2;
}