#include "objects.hpp"
#include "../resources/resources.hpp"
//#include<iostream>

long double Player::Player::CalculateFeet()
{
    return (bodyPart.ReturnPositionY() - bodyPart.ReturnHeight() / 2);
}

Player::Character::Character():headPart{DEFAULT_CENTERX, DEFAULT_CENTERY + DEVIATION, DEFAULT_RADIUS, 50},
                               bodyPart{DEFAULT_CENTERX,DEFAULT_CENTERY,DEFAULT_HEIGHT,DEFAULT_WIDTH}{}
EmptyReturn Player::Player::Render()
{
    bodyPart.render();
    headPart.render();
}

Grounded Player::Player::OnGround()
{
    return isGrounded;
}

EmptyReturn Player::Player::UpdateJump()
{
    if(isGrounded)
    {
        FallingSpeed = abs(FallingSpeed);
        isGrounded = false;
        isInJump = true;
    }
}

EmptyReturn Player::Player::UpdateHeightToTouch()
{
    MaximumHeightToTouch = bodyPart.ReturnPositionY() + maxHeightJump;
}
EmptyReturn Player::Player::CheckMaxHeight()
{
    auto LowerThanSecond = [](CenterYPosition Player, CenterYPosition MaxHeight)
                                {
                                    return MaxHeight > Player;
                                };

    if(!LowerThanSecond(bodyPart.ReturnPositionY(), MaximumHeightToTouch))
    {
        bodyPart.OverWriteCenter(bodyPart.ReturnPositionX(), MaximumHeightToTouch + OFFSET);
        headPart.OverWriteCenter(headPart.ReturnPositionX(), MaximumHeightToTouch + bodyPart.ReturnHeight()/2 + OFFSET);
        isInJump = false;
        FallingSpeed = -abs(FallingSpeed);
    }
}

EmptyReturn Player::Player::UpdatePositions(DeltaTimeType DeltaTime)
{
    headPart.UpdateCenter( dx ,  FallingSpeed * DeltaTime);
    bodyPart.UpdateCenter( dx ,  FallingSpeed * DeltaTime);

    if(isInJump)
    {
        CheckMaxHeight();
    }
}

