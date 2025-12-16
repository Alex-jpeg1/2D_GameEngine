#pragma once
#include <GLFW/glfw3.h>
#include <csetjmp>
#include <type_traits>
#include <math.h>
#include <cmath> 

constexpr long double PI = 3.14159;
constexpr long long SCALING_FACTOR = 100000000000LL; 
extern long double contor;

enum class CollisionStates
{
    NoCollision,
    HeadCollision,
    BodyCollision,
    FeetCollision
};


namespace BasicObject
{
    class BasicObject
    {
        public:
            BasicObject();
            BasicObject(long double _CenterX, long double _CenterY);
            virtual void UpdateCenter(long double _UpdateX, long double _UpdateY);
        protected:
            long double CenterX,CenterY;
    };
    //The basic object will check for collisions with every other object
    //The basic object will check for the relative position of the surrounding objects
    //The basic object will then compose the square and the circle hitboxes
}

namespace HitBox
{ 
class HalfCircle: public BasicObject::BasicObject
{
    public:
        HalfCircle();
        HalfCircle(long double _CenterX, long double _CenterY, long double _radius, int _NumberVertices);
        void render() const;
        //template <class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& object);

    private:
        const int NumberVertices;
        const long double radius;
};
class Square: public BasicObject::BasicObject
{
    public: 
        Square();
        Square(long double _CenterX, long double _CenterY, long double _Height, long double _Width);
        void render() const;
        long double ReturnPositionY() const ;
        long double ReturnHeight() const ;
        long double ReturnTop() const ;
        long double ReturnPositionX() const ;
        long double ReturnWidth() const ;
        long double ReturnLeft() const ;
        long double ReturnRight() const ;
        long double ReturnBottom() const;

        //template<class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& Object);

    protected:
        long double Height,Width;
};
};

namespace Surrounding
{
    class Ground: public HitBox::Square
    {
        public:
            Ground(long double _CenterX, long double _CenterY, long double _Height, long double _Width, int _Position);
            long double ReturnTop() const;
            long double ReturnLeft() const;
            long double ReturnRight() const; 

            void Recenter();

            //This function is needed to redraw the surrounding terrain relative to the seated position of the player to not have evergrowing terrain
        private:
            int Position;
    };
    //The ground will have a square hitbox 
    //The ground will be positioned on the lowest part of the whole game
    //The ground will also be composed of some hills like structure
    //The ground will have a specific identifier to be able to assign a sprite to it 
}

namespace Player
{

    class Player
    {
        public:
            Player();
            template<class ColisionObject> void CheckCollision(ColisionObject& Object)
            {
                if constexpr (std::is_same_v<ColisionObject, Surrounding::Ground>)
                {
                    if(((bodyPart.ReturnTop() > Object.ReturnBottom()) && (bodyPart.ReturnBottom() < Object.ReturnTop())))
                    {
                        if(bodyPart.ReturnBottom() < Object.ReturnTop())
                        {
                            contor = bodyPart.ReturnBottom();
                        }
                        // Scalare
                        long long playerRightScaled = (long long)(bodyPart.ReturnRight() * SCALING_FACTOR);
                        long long objectLeftScaled = (long long)(Object.ReturnLeft() * SCALING_FACTOR);
                        long long playerLeftScaled = (long long)(bodyPart.ReturnLeft() * SCALING_FACTOR);
                        long long objectRightScaled = (long long)(Object.ReturnRight() * SCALING_FACTOR);

                        if(Object.ReturnPositionX() > bodyPart.ReturnPositionX())
                        {
                            if(bodyPart.ReturnRight() > Object.ReturnLeft())
                            {
                                long double updateX = (long double)(objectLeftScaled - playerRightScaled) / SCALING_FACTOR;
                                headPart.UpdateCenter(updateX, 0);
                                bodyPart.UpdateCenter(updateX, 0);
                            }
                        }
                        else if(Object.ReturnPositionX() < bodyPart.ReturnPositionX())
                        {
                            if(Object.ReturnRight() > bodyPart.ReturnLeft())
                            {
                                long double updateX = (long double)(objectRightScaled - playerLeftScaled) / SCALING_FACTOR;
                                headPart.UpdateCenter(updateX, 0);
                                bodyPart.UpdateCenter(updateX, 0);   
                            }
                        }
                    }
                    if(bodyPart.ReturnLeft() < Object.ReturnRight() && bodyPart.ReturnRight() > Object.ReturnLeft())
                    {
                        long long calculateFeetScaled = (long long)(CalculateFeet() * SCALING_FACTOR);
                        long long objectTopScaled = (long long)(Object.ReturnTop() * SCALING_FACTOR);

                        if(CalculateFeet() < Object.ReturnTop())
                        {
                            long double penetrationDepth = (long double)(objectTopScaled - calculateFeetScaled - OffSet * SCALING_FACTOR) / SCALING_FACTOR;

                            hasGround = true;
                            headPart.UpdateCenter(0, penetrationDepth);
                            bodyPart.UpdateCenter(0, penetrationDepth);
                            isGrounded = true;
                        }
                        else 
                        {
                            isGrounded = false;
                            hasGround = false;
                        }
                    }
                    else if(!hasGround) 
                    {
                        isGrounded = false;
                    }
                    //This is the collision for the ground
                }
            }
            //Templated function to not rewrite every type of collision with every object 
            //This function will call the specific object Collision  
            void UpdatePositions(GLFWwindow* window, long double DeltaTime)
            {
                if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
                {
                    headPart.UpdateCenter(velocity * DeltaTime, 0);
                    bodyPart.UpdateCenter(velocity * DeltaTime, 0);
                    //Update the X position of the objects 
                }
                if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
                {
                    headPart.UpdateCenter(-velocity * DeltaTime, 0);
                    bodyPart.UpdateCenter(-velocity * DeltaTime, 0);
                    //Update the X position of the objects 
                }
                if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && isGrounded)
                {
                    FallingSpeed = abs(FallingSpeed);
                    isGrounded = false;
                    MaximumHeightTouched = bodyPart.ReturnPositionY() + maxHeightJump;
                    isInJump = true;
                    hasGround = false;
                }
                if(!isGrounded)
                {
                    bodyPart.UpdateCenter(0, FallingSpeed * DeltaTime);
                    headPart.UpdateCenter(0, FallingSpeed * DeltaTime);

                    if(isInJump && bodyPart.ReturnPositionY() >= MaximumHeightTouched)
                    {
                        long long maxHitScaled = (long long)(MaximumHeightTouched * SCALING_FACTOR);
                        long long bodyYScaled = (long long)(bodyPart.ReturnPositionY() * SCALING_FACTOR);

                        long double correction = (long double)(maxHitScaled - bodyYScaled ) / SCALING_FACTOR;

                        headPart.UpdateCenter(0, correction );
                        bodyPart.UpdateCenter(0, correction );
                        FallingSpeed = -abs(FallingSpeed);
                        isInJump = false;
                    }
                }
            }

            void Render()
            {
                bodyPart.render();
                headPart.render();
            }
        private:
            long double CalculateFeet();
            HitBox::HalfCircle headPart;
            HitBox::Square bodyPart;
            const long double velocity = 0.3;  
            long double FallingSpeed = -1.8;
            bool isGrounded=false;
            long double maxHeightJump = 0.4;
            long double MaximumHeightTouched = 0; 
            long double isInJump = false;
            bool hasGround = false;
            long double OffSet = 0.000000000001;
        //The hitbox of a player will be created from 2 objects a Circle and a square
        //The head will interact with either a ceiling or other flying objects 
        //The body will interact with the ground, slopes or any other part
        //The game i intend to create will be pixelated so i do not need a circle as the body to create smoothness as the enviroment will be square
    };
}