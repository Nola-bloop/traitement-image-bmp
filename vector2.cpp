#include "vector2.h"

#include <cmath>

int Vector2::getNormal()
{
    return std::sqrt(
        std::pow(this->a, 2)
        +
        std::pow(this->b, 2)
    );
}

int Vector2::getTheta()
{
    bool right = this->a / std::abs(this->a) & 1;
    bool top = this->b / std::abs(this->b) & 1;



    //formule principale
    int rawTheta = std::atan(
        std::abs(this->b) 
        / 
        std::abs(this->a)
    );


    //trouver la vraie valeur de theta
    int theta{0};

    if (top && right){
        theta = rawTheta;
    }
    else if (top && !right){
        theta = 180 - rawTheta;
    }
    else if (!top && !right){
        theta = 180 + rawTheta;
    }else{
        theta = 360 - rawTheta;
    }

    return theta;
}

int Vector2::farthestX()
{
    if (this->a > this->x)
        return this->a;
    else
        return this->x;
}
int Vector2::farthestY()
{
    if (this->b > this->y)
        return this->b;
    else
        return this->y;
}

int Vector2::closestX()
{
    if (this->a < this->x)
        return this->a;
    else
        return this->x;
}
int Vector2::closestY()
{
    if (this->b < this->y)
        return this->b;
    else
        return this->y;
}