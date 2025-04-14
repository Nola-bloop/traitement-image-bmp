#pragma once

#include <vector>

#include "rgba.h"
#include "vector2.h"

class IDrawable
{
public:
    RGBA color{0,0,0,100}; //couleur de base
    Vector2 pos;

    /// @brief Trouver tous les indexes à colorer
    /// @param w width du canvas
    /// @return une liste de tous les indexes à colorer.
    virtual std::vector<int> Draw(int w) = 0;
};
