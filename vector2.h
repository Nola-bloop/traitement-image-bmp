#pragma once

struct Vector2
{
    int x{0};
    int y{0};
    int a{0};
    int b{0};
    int normal{0};
    int theta{0};

    int getNormal();
    int getTheta();

    /// @brief farthest X coordinate between x and a to the right
    /// @return 
    int farthestX();

    /// @brief farthest Y coordinate between y and b going upwards
    /// @return 
    int farthestY();

    /// @brief closest X coordinate between x and a to the left
    /// @return 
    int closestX();

    /// @brief closest Y coordinate between y and b (farthest one going downwards)
    /// @return 
    int closestY();
};
