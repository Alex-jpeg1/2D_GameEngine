#pragma once
constexpr double PI = 3.14159;


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

    };
    //The basic object will check for collisions with every other object
    //The basic object will check for the relative position of the surrounding objects
    //The basic object will then compose the square and the circle hitboxes
}

namespace HitBox
{ 
class Circle 
{
    public:
        Circle(double _CenterX, double _CenterY, double _radius);
        void render() const;
        void UpdateCenter(double _UpdateX, double _UpdateY);
    private:
        const int NumberVertices = 100;
        double CenterX,CenterY; 
        const double radius;
};
class Square
{
    public: 
        Square(double _CenterX, double _CenterY, double _Height, double _Width);
        void render() const;
        template<class CollisionObject>
        CollisionStates CheckCollision(CollisionObject& Object) const;

    private:
        const double CenterX,CenterY;
        const double Height,Width;
};
};

namespace Player
{

    class Player
    {
        public:
            template<class ColisionObject>
            CollisionStates CheckCollision(ColisionObject& Object) const;
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
