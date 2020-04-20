#ifndef ASTARDATA_H
#define ASTARDATA_H
#include "maze_point.h"
#include <GL/glew.h>

class AStarData
{
public:
    MazePoint Point;
    GLfloat G;
    GLfloat H;
    AStarData *Parent;

    AStarData(MazePoint &p, GLfloat g, GLfloat h)
    : Point(p), G(g), H(h) , Parent(NULL){}

    GLfloat GetF()
    {
        return G + H;
    }
};

#endif 