#include "objects.hpp"

long double Player::Player::CalculateFeet()
{
    return (bodyPart.ReturnPositionY() - bodyPart.ReturnHeight() / 2);
}

