//
// Created by romens on 2019-04-02.
//

#include "ScatterTopRight.h"

ScatterTopRight::ScatterTopRight() {}
ScatterTopRight::~ScatterTopRight() {}

Direction ScatterTopRight::Scatter(MazePoint *startPoint)
{
    MazePoint *endPoint = new MazePoint(19, 2);
    return this->LocalMaze.Search(startPoint, endPoint);
}
