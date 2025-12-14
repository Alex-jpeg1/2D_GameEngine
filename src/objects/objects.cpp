#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "objects.hpp"

HitBox::Circle::Circle(double _CenterX, double _CenterY, double _radius): CenterX{_CenterX}, CenterY{_CenterY}, radius{_radius}{}

void HitBox::Circle::render() const
{

    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);

    for(int i{0}; i<=NumberVertices; i++)
    {
        double angle = (2 * PI) * (static_cast<double>(i) / static_cast<double>(NumberVertices));
        float x = CenterX + radius*cos(angle);
        float y = CenterY + radius*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
}
void HitBox::Circle::UpdateCenter(double _UpdateX, double _UpdateY)
{
    CenterX += _UpdateX;
    CenterY += _UpdateY;
}

HitBox::Square::Square(double _CenterX, double _CenterY, double _Height, double _Width):
                                                                                        CenterX{_CenterX},
                                                                                        CenterY{_CenterY},
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