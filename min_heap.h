#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <unordered_map>
#include <string>
#include "maze_point.h"
#include "a_star_data.h"

class MinHeap
{
public:
    MinHeap();
    MinHeap(int endPoint);
    ~MinHeap();

    std::string GetKey(MazePoint &p);
    bool IsEmpty();
    AStarData *Find(MazePoint &p);
    void Add(AStarData &data);
    AStarData *GetAndRemoveMin();
private:
    void BottomUp();
    void TopDown();
    int EndPoint;
    std::vector<AStarData *> Queue;
    std::unordered_map<std::string, AStarData *> AStarIndex;
};

#endif