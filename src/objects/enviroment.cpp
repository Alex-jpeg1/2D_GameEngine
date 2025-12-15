#include "objects.hpp"

Surrounding::Ground::Ground(){}

double Surrounding::Ground::ReturnTop() const
{
    return CenterY + Height / 2;
}
double Surrounding::Ground::ReturnBottom() const
{
    return CenterY - Height / 2;
}
double Surrounding::Ground::ReturnLeft() const
{
    return CenterX - Width / 2;
}
double Surrounding::Ground::ReturnRight() const
{
    return CenterX - Width / 2;
}
//These are only getters for the values to then check collision
