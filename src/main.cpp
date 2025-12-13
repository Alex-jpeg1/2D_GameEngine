#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <math.h>
#include <thread>
constexpr double PI = 3.14159;

namespace HitBox
{ 
class Circle 
{
    public:
        Circle(double _CenterX, double _CenterY, double _radius): CenterX{_CenterX}, CenterY{_CenterY}, radius{_radius}{}
        void render() const
        {

            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_TRIANGLE_FAN);

            for(int i{0}; i<=NumberVertices; i++)
            {
                double angle = (2 * PI) * (static_cast<double>(i) / static_cast<double>(NumberVertices));
                float x = CenterX + radius*cos(angle);
                float y = CenterY + radius*sin(angle);
                glVertex2f(x,y);
            }
            glEnd();
        }
        void UpdateCenter(double _UpdateX, double _UpdateY)
        {
            CenterX += _UpdateX;
            CenterY += _UpdateY;
        }
    private:
        const int NumberVertices = 100;
        double CenterX,CenterY; 
        const double radius;
};
class Square
{
    public: 
        Square(double _CenterX, double _CenterY, double _Height, double _Width):
        CenterX{_CenterX},
        CenterY{_CenterY},
        Height{_Height},
        Width{_Width}{}

        void render() const
        {
            glBegin(GL_TRIANGLES);

            double HalfHeight = Height/2;
            double HalfWidth = Width/2;

            float YUp = CenterY + HalfHeight;
            float YDown = CenterY - HalfHeight;
            float XRight = CenterX + HalfWidth;
            float XLeft = CenterX - HalfWidth;

            glVertex2f(XRight, YUp);
            glVertex2f(XRight,  YDown);
            glVertex2f(XLeft, YDown);

            glVertex2f(XRight, YUp);
            glVertex2f(XLeft, YDown);
            glVertex2f(XLeft, YUp);

            glEnd();
        }
    private:
        const double CenterX,CenterY;
        const double Height,Width;
};
};
//These will be the main components for hitboxes

namespace Player
{
    enum class CollisionStates
    {
        NoCollision,
        HeadCollision,
        BodyCollision,
        FeetCollision
    };

    class Player
    {
        public:
            template<class ColisionObject>
            CollisionStates CheckCollision(ColisionObject& Object) const
            {
                
            }
            //templated function to not rewrite every type of collision with every object 
        private:
            HitBox::Circle headPart;
            HitBox::Square bodyPart;
        //The hitbox of a player will be created from 2 objects a Circle and a square
        //The head will interact with either a ceiling or other flying objects 
        //The body will interact with the ground, slopes or any other part
        //The game i intend to create will be pixelated so i do not need a circle as the body to create smoothness as the enviroment will be square
    };
}

int main() {
    HitBox::Circle circle(0.0,0.0,0.5);
    HitBox::Square square(0,0,0.8,0.8);
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Tutorial", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    
    while (!glfwWindowShouldClose(window)) {
        square.render();
        circle.render();
        circle.UpdateCenter(0.02,0.02);
        glfwSwapBuffers(window);
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
