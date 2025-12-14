#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>
#include "objects/objects.hpp"

double TargetFrameRate = 1.0/100.0;

//These will be the main components for hitboxes

void Update()
{
    HitBox::Circle circle(0.0,0.1,0.05);
    HitBox::Square square(0,0,0.2,0.1);
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(1000, 900, "OpenGL Tutorial", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    static auto LastTime = std::chrono::high_resolution_clock::now();
    while (!glfwWindowShouldClose(window)) 
    {
        auto CurrentTime = std::chrono::high_resolution_clock::now();
        square.render();
        circle.render();
        //circle.UpdateCenter(0.02,0.02);
        glfwSwapBuffers(window);
        glfwPollEvents();

        auto EndTime = std::chrono::high_resolution_clock::now();
        auto DurationTime = EndTime - CurrentTime;

        if(TargetFrameRate > DurationTime.count())
        {
            double SleepTime = TargetFrameRate - DurationTime.count();

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

