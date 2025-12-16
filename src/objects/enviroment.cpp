#include "objects.hpp"

Surrounding::Ground::Ground(long double _CenterX,long double _CenterY,long double _Height,long double _Width, int _Position):HitBox::Square{_CenterX,
                                                                                                            _CenterY,
                                                                                                            _Height,
                                                                                                            _Width}
                                                                                                            ,
                                                                                                            Position(_Position){}
                                                                                            
long double Surrounding::Ground::ReturnTop() const
{
    return CenterY + Height / 2;
}
long double Surrounding::Ground::ReturnLeft() const
{
    return CenterX - Width / 2;
}
long double Surrounding::Ground::ReturnRight() const
{
    return CenterX + Width / 2;
}
//These are only getters for the values to then check collision
