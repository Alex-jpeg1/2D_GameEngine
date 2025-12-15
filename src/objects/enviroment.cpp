#include "objects.hpp"

Surrounding::Ground::Ground(double _CenterX, double _CenterY, double _Height, double _Width, int _Position):HitBox::Square{_CenterX,
                                                                                                            _CenterY,
                                                                                                            _Height,
                                                                                                            _Width}
                                                                                                            ,
                                                                                                            Position(_Position){}
                                                                                            
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
    return CenterX + Width / 2;
}
//These are only getters for the values to then check collision
