//
// Created by romens on 2019-04-02.
//

#ifndef TETRIS_SCATTERTOPRIGHT_H
#define TETRIS_SCATTERTOPRIGHT_H

#include "ScatterStrategy.h"

class ScatterTopRight : public ScatterStrategy
{
public:
    ScatterTopRight();
    ~ScatterTopRight();

    virtual Direction Scatter(MazePoint *startPoint);
};

#endif //TETRIS_SCATTERTOPRIGHT_H
