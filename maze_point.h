#ifndef MAZEPOINT_H
#define MAZEPOINT_H

#include "ghost_object.h"

class MazePoint
{
public:
    Direction DirFromParent;
    unsigned int X;
    unsigned int Y;

    MazePoint(int x, int y)
        : X(x), Y(y) {}
    
    bool Equals(MazePoint &p)
    {
        return this->X == p.X && this->Y == p.Y;
    }
};

#endif 