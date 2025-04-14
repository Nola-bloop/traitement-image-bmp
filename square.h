#pragma once

#include "IDrawable.h"
#include "rgba.h"
#include "vector2.h"

#include <vector>

class Square : IDrawable
{
private:
    int w{1};
    int h{0};
public:
    /// @brief Constructeur d'un carré
    /// @param pos vector2 element that specifies the position and size
    /// @param col RGBA color
    Square(Vector2 pos, RGBA col);
    ~Square();

    /// @brief trouver tous les indexes où dessiner
    /// @param w : width de l'image
    /// @return les indexes où dessiner
    std::vector<int> Draw(int w);
};
