#include "Player.hpp"
#include "objects.hpp"

Player::Player::Player(const XValue& XPosition, const YValue& YPosition, const XValue& width, const YValue& height, GetShaderType::TileType TextureType)
:Objects::GameObject(XPosition, YPosition, width, height, TextureType), _Gravity()
{}