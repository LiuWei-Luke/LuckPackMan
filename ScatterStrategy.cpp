//
// Created by romens on 2019-04-02.
//

#include "ScatterStrategy.h"

ScatterStrategy::ScatterStrategy() : LocalMaze()
{
    this->LocalMaze.Load("../maze/maze.lvl", 690, 630);
}
ScatterStrategy::~ScatterStrategy() {}