#include "objects.hpp"
#include "../resources/resources.hpp"

long double Player::Player::CalculateFeet()
{
    return (bodyPart.ReturnPositionY() - bodyPart.ReturnHeight() / 2);
}

void Player::Character::Render()
{
    bodyPart.render();
    headPart.render();
}

Player::Character::Character():headPart{DEFAULT_CENTERX, DEFAULT_CENTERY + DEVIATION, DEFAULT_RADIUS, 50},
                               bodyPart{DEFAULT_CENTERX,DEFAULT_CENTERY,DEFAULT_HEIGHT,DEFAULT_WIDTH}
{
}


long double Player::Player::

