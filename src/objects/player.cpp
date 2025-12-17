#include "objects.hpp"
#include "../resources/resources.hpp"

long double Player::Player::CalculateFeet()
{
    return (bodyPart.ReturnPositionY() - bodyPart.ReturnHeight() / 2);
}

Player::Character::Character():headPart{DEFAULT_CENTERX, DEFAULT_CENTERY + DEVIATION, DEFAULT_RADIUS, 50},
                               bodyPart{DEFAULT_CENTERX,DEFAULT_CENTERY,DEFAULT_HEIGHT,DEFAULT_WIDTH}{}
void Player::Player::Render()
{
    bodyPart.render();
    headPart.render();
}

void Player::Player::UpdateJump()
{
    FallingSpeed = 0;
    isGrounded = false;
    isInJump = true;
}

void Player::Player::UpdatePositions(DeltaTimeType DeltaTime)
{
    headPart.UpdateCenter(headPart.ReturnPositionX() + dx * DeltaTime, headPart.ReturnPositionY() + FallingSpeed * DeltaTime);
    bodyPart.UpdateCenter(bodyPart.ReturnPositionX() + dx * DeltaTime, bodyPart.ReturnPositionY() + FallingSpeed * DeltaTime);
}
