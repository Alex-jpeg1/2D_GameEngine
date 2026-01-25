#pragma once

#include "../GameEngine_all.hpp"

enum class WC_Messages
{
    WC_Succesfull,
    WC_Fail
};



class WindowObject
{
    private:
    
    struct WindowHint
    {
        int target;
        int Value;
    };

    public:
    WindowObject();
    WindowObject(const WindowHeight&, const WindowWidth& windowWidth);

    WindowObject(const WindowObject&) = delete;
    void operator=(const WindowObject&) = delete;

    WindowObject(WindowObject&&);
    WindowObject operator=(WindowObject&&);

    EmptyReturn DefaultHints();
    EmptyReturn SetHints(std::initializer_list<WindowHint>);
    ~WindowObject();

    [[ nodiscard ]] WC_Messages GetCreationMessage() noexcept {return _ErrorMsg;};

    [[ nodiscard ]] bool WindowShouldClose() noexcept { return glfwWindowShouldClose(_window); }

    EmptyReturn BufferSwap() noexcept { glfwSwapBuffers(_window); }
    private:

    EmptyReturn CreateContext();

    const WindowHeight _WindowHeight;
    const WindowWidth _WindowWidth;
    GLFWwindow* _window;
    WC_Messages _ErrorMsg;
};