#pragma once
#include<queue>
#include "../objects/objects.hpp"
#include <chrono>

using TimePoint = std::chrono::high_resolution_clock::time_point;

struct KeyEvent
{
    KeyEvent(const int& _key, const int& _scancode, const int& _action, const int& _mods,const TimePoint& _inputTime);
    int key, scancode, action, mods;
    TimePoint inputTime;
};

extern std::queue<KeyEvent> UnhandledInputs;

EmptyReturn HandleInput(Player::Player& player, const TimePoint& MaximumTimePoint);