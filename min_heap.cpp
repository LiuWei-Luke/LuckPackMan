#include "min_heap.h"
#include <iostream>

std::string intToString(int v);

MinHeap::MinHeap(int endPoint)
    : EndPoint(endPoint) {}

MinHeap::~MinHeap()
{
    this->AStarIndex.clear();
}

std::string MinHeap::GetKey(MazePoint &p)
{
    std::string s;
    s += intToString(p.X);
    s += "--";
    s += intToString(p.Y);
    return s;
}

bool MinHeap::IsEmpty()
{
    return this->EndPoint <= 0;
}

AStarData *MinHeap::Find(MazePoint &p)
{
    auto result = this->AStarIndex.find(this->GetKey((p)));
    if (result != this->AStarIndex.end())
    {
        return result->second;
    }
    else
    {
        return NULL;
    }
}

AStarData *MinHeap::GetAndRemoveMin()
{
    if (!this->IsEmpty())
    {
        AStarData *head = this->Queue[0];
        AStarData *last = this->Queue[this->EndPoint - 1];
        this->Queue[0] = last;
        this->EndPoint -= 1;

        this->Queue.pop_back();
        this->AStarIndex.erase(this->GetKey(head->Point));

        this->TopDown();

        return head;
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }
}

void MinHeap::Add(AStarData &data)
{
    if (this->Queue.size() > this->EndPoint)
    {
        this->Queue[EndPoint] = &data;
    }
    else
    {
        this->Queue.push_back(&data);
    }
    this->EndPoint += 1;
    this->AStarIndex.insert({this->GetKey(data.Point), &data});

    this->BottomUp();
}

void MinHeap::BottomUp()
{
    for (int i = this->EndPoint - 1; i >= 0;)
    {
        int parentNode = (i - 1) / 2;
        if (parentNode < 0)
        {
            break;
        }
        AStarData *curData = this->Queue[i];
        AStarData *parentData = this->Queue[parentNode];

        if (parentData->GetF() > curData->GetF())
        {
            this->Queue[parentNode] = curData;
            this->Queue[i] = parentData;
            i = parentNode;
        }
        else
        {
            break;
        }
    }
}

void MinHeap::TopDown()
{
    int cur = 0;
    int l = 2 * cur + 1;
    AStarData *tmp = this->Queue[cur];

    while (l <= this->EndPoint-1)
    {
        if (l < this->EndPoint-1 && this->Queue[l]->GetF() > this->Queue[l+1]->GetF())
            l += 1;
        if (this->Queue[cur]->GetF() < this->Queue[l]->GetF())
            break;
        else
        {
            this->Queue[cur] = this->Queue[l];
            cur = l;
            l = 2 * cur + 1;
        }

    }

    this->Queue[cur] = tmp;
}

std::string intToString(int v)
{
    char buf[32] = {0};
    snprintf(buf, sizeof(buf), "%u", v);

    std::string str = buf;
    return str;
}
