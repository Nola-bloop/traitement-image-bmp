#include "square.h"
#include "rgba.h"
#include "vector2.h"

#include <stdexcept>
#include <vector>
#include <math.h>

Square::Square(Vector2 pos, RGBA col){
    //sanity
    if (pos.getNormal() < 1){ std::__throw_invalid_argument("Le carré ne peut pas avoir une taille plus petite que 1 !"); }
    
    this->color = col;
    this->pos = pos;
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
