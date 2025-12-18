#include "KeyEvents.hpp"



KeyEvent::KeyEvent(const int& _key, const int& _scancode, const int& _action, const int& _mods):key(_key),
                                                                                                scancode(_scancode),
                                                                                                action(_action),
                                                                                                mods(_mods){}

void HandleInput()
{
    
}