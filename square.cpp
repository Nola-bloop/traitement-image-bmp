#include "square.h"
#include "rgba.h"
#include "vector2.h"

#include <vector>
#include <cmath>
#include <stdint.h>

Square::Square(Vector2 pos){
    //sanity
    //if (pos.getNormal() < 1)
        //std::__throw_invalid_argument("Le carré ne peut pas avoir une taille plus petite que 1 !");
    
    this->pos = pos;
}

Square::Square(int x, int y, int cx, int cy)
{
    Vector2 v{x, y, cx, cy};
    //if (v.getNormal() < 1)
        //std::__throw_invalid_argument("Le carré ne peut pas avoir une taille plus petite que 1 !");

    this->pos = v;
}

std::vector<int> Square::Draw(int w)
{
    std::vector<int> out;

    for (int i{this->pos.closestY()}; i < this->pos.farthestY(); i++){
        for (int j{this->pos.closestX()}; j < this->pos.farthestX(); j++){
            out.push_back((w*i)+j);
        }
    }


    return out;
}
