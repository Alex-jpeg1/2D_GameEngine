#include "objects.hpp"

double Player::Player::CalculateFeet()
{
    return (bodyPart.ReturnPositionY() - bodyPart.ReturnHeight() / 2);
}

