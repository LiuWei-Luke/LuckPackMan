//
// Created by romens on 2019-04-02.
//

#ifndef TETRIS_SCATTERSTRATEGY_H
#define TETRIS_SCATTERSTRATEGY_H

#include "maze.h"

class ScatterStrategy
{
public:
    Maze LocalMaze;
    ~ScatterStrategy();

    virtual Direction Scatter(MazePoint *startPoint) = 0;
protected:
    ScatterStrategy();
};


#endif //TETRIS_SCATTERSTRATEGY_H
