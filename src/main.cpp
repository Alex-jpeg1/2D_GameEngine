#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>
#include "objects/objects.hpp"
#include <iostream>
constexpr std::chrono::duration<double> TargetFrameRate = std::chrono::duration<double>(1.0/100.0);

//These will be the main components for hitboxes

void Update()
{
    Player::Player player;
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1000, 900, "OpenGL Tutorial", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    static auto LastTime = std::chrono::high_resolution_clock::now();
    while (!glfwWindowShouldClose(window)) 
    {
        auto CurrentTime = std::chrono::high_resolution_clock::now();
        glClear(GL_COLOR_BUFFER_BIT);
        
        player.Render();
        std::chrono::duration<double> RawDeltaTime = CurrentTime-LastTime;
        double DeltaTime = RawDeltaTime.count(); 
        player.UpdatePositions(window,DeltaTime);
        std::cout<<DeltaTime<<'\n';
        
        glfwSwapBuffers(window);
        glfwPollEvents();

        auto EndTime = std::chrono::high_resolution_clock::now();
        auto DurationTime = EndTime - CurrentTime;
        LastTime = CurrentTime;
        if(TargetFrameRate > DurationTime)
        {
            auto SleepTime = TargetFrameRate - DurationTime;

            std::this_thread::sleep_for(SleepTime);
        }
    }
    //The main loop
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main() 
{
    Update();
    return 0;
}
//The Update Function will play in the main thread to draw in there
//TO DO implement a second thread to load in the data of the current scene

