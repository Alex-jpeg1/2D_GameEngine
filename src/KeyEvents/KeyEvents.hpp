#pragma once
#include<queue>
#include "../objects/objects.hpp"


struct KeyEvent
{
    KeyEvent(const int& _key, const int& _scancode, const int& _action, const int& _mods);
    int key, scancode, action, mods;
};

extern std::queue<KeyEvent> UnhandledInputs;

void HandleInput();