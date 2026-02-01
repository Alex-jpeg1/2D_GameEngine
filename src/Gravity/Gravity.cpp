#include "Gravity.hpp"

Alex::GravityComponent::GravityComponent(bool isInitialized, Vector2DCustom::vect2d PozitiiOriginale)
    :_gravitationalAcceleration{isInitialized?static_cast<GLfloat>(9.8): static_cast<GLfloat>(0)},
     _transMatrix{MatrixFactory(PozitiiOriginale)}
{}

EmptyReturn Alex::GravityComponent::UpdateVelocity(GLfloat DeltaTime)
{
    _velocity += DeltaTime * _gravitationalAcceleration;
}
EmptyReturn Alex::GravityComponent::GroundedObject()
{
    _velocity = 0;
}
Alex::MatrixFactory::MatrixFactory(Vector2DCustom::vect2d PozitiiOriginale)
    :_position{PozitiiOriginale.GetXVal(), PozitiiOriginale.GetYVal()},
    _modelMatrix(1.0)
{}