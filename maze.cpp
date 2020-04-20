#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <math.h>
#include "maze.h"
#include "min_heap.h"



void Maze::Load(const GLchar *file, GLuint mazeWidth, GLuint mazeHeight)
{

    this->Elements.clear();
    GLuint elementCode;
    std::string line;
    std::ifstream fstream(file);
    std::vector <std::vector <GLuint> > elementData;

    if (fstream)
    {
        while(std::getline(fstream, line))
        {
            std::istringstream sstream(line);
            std::vector<GLuint> row;
            while (sstream >> elementCode)
            {
                row.push_back(elementCode);
            } 
            elementData.push_back(row);
        }

        if (elementData.size() > 0)
        {
            this->MazeData = elementData;
            this->init(elementData, mazeWidth, mazeHeight);
        }

    }
}

void Maze::Draw(SpriteRenderer &renderer)
{
  for(MazeObject &element : this->Elements)
  {
    if (!element.IsBit)
    {
        element.Draw(renderer);
    }
  }
}

void Maze::init(std::vector <std::vector <GLuint> > elementData,  GLuint mazeWidth, GLuint mazeHeight)
{
    //计算分辨率
    GLuint height = elementData.size();
    GLuint width = elementData[0].size();
    GLfloat uint_width = mazeWidth / static_cast<GLfloat>(width);
    GLfloat uint_height = mazeHeight / height;
    this->UnitWidth = uint_width;
    this->UnitHeight = uint_height;
    this->row = height;
    this->column = width;
    this->MazeData = elementData;

  //初始化
  for(GLuint y = 0; y < height; ++y)
  {
    for(GLuint x = 0; x < width; ++x)
    {
        switch(elementData[y][x])
        {
            case 4:
            {
                glm::vec2 pos(uint_width * x, uint_height * y);
                glm::vec2 size(uint_width, uint_height);
                MazeObject obj(pos, size, ResourceManager::GetTexture("pill"),
                               glm::vec3(0.0f, 1.0f, 0.0f));
                obj.IsSolid = GL_FALSE;
                obj.IsBean = GL_TRUE;
                obj.IsPower = GL_TRUE;
                this->Elements.push_back(obj);
            }
                break;
            case 2:
                {
                    glm::vec2 pos(uint_width * x, uint_height * y);
                    glm::vec2 size(uint_width, uint_height);                    
                    MazeObject obj(pos, size, ResourceManager::GetTexture("block_solid"),
                                glm::vec3(0.8f, 0.8f, 0.7f));
                    obj.IsSolid = GL_TRUE;
                    obj.IsBean = GL_FALSE;
                    this->Elements.push_back(obj);
                }
                break;
            case 1:
                {
                    glm::vec2 pos(uint_width * x, uint_height * y);
                    glm::vec2 size(uint_width, uint_height);                    
                    MazeObject obj1(pos, size, ResourceManager::GetTexture("pill"),
                                glm::vec3(1.0f));
                    obj1.IsSolid = GL_FALSE;
                    obj1.IsBean = GL_TRUE;
                    this->Elements.push_back(obj1);                    
                }
                break;
            case 0:
                {
                    glm::vec2 pos(uint_width * x, uint_height * y);
                    glm::vec2 size(uint_width, uint_height);                    
                    MazeObject obj2(pos, size, ResourceManager::GetTexture("block"),
                                glm::vec3(0.0f));
                    obj2.IsSolid = GL_FALSE;
                    obj2.IsBean = GL_FALSE;
                    this->Elements.push_back(obj2); 
                }
                break;
        }
    }
  }    
}

GLboolean Maze::IsCompleted()
{
  for(MazeObject &tile : this->Elements)
    if (tile.IsBean && !tile.IsBit)
      return GL_FALSE;
  return GL_TRUE;
}

MazePoint *Maze::GetMazePoint(GhostObject &ghost)
{
    GLfloat  pX = ghost.Position.x;
    GLfloat  pY = ghost.Position.y;

    if (pX < 0)
    {
        pX = 0.0f;
    }

    if (pX > (this->UnitWidth * this->column))
    {
        pX = this->UnitWidth * this->column;
    }


    int rX = floor(pX/this->UnitWidth);
    int rY = floor(pY/this->UnitHeight);

    auto *p = new MazePoint(rX, rY);
    return p;
}

bool Maze::InCorner(GhostObject &ghost)
{
    MazePoint *p = this->GetMazePoint(ghost);
    bool flag = false;
    for (auto &point : this->CornerData)
    {
        if (p->X == point[0] && p->Y == point[1])
        {
            flag = true;
        }
    }

    return flag;
}

GLfloat hEuclidianDistance(MazePoint &point, MazePoint &endPoint);
GLfloat hPowEuclidianDistance(MazePoint &point, MazePoint &endPoint);
GLfloat hManhattanDistance(MazePoint &point, MazePoint &endPoint);

Direction Maze::Search(MazePoint *startPoint, MazePoint *endPoint, GhostType type)
{
    std::unordered_map<std::string, AStarData *> closedIndex;

    auto *heap = new MinHeap(0);
    std::vector <std::vector <int> > directs = {
            {0, -1}, {1, 0}, {0, 1}, {-1, 0}
    };

    auto *startData = new AStarData(*startPoint, 0.0f, 0.0f);
    AStarData *lastData = nullptr;
    AStarData *endData = nullptr;
    heap->Add(*startData);

    bool isFinish = false;

    while (!isFinish && !heap->IsEmpty())
    {
        //取出当前访问过的点中F值最小的点
        AStarData *minValueData = heap->GetAndRemoveMin();
        MazePoint minValuePoint = minValueData->Point;

        //将其插入已访问数组
        closedIndex.insert({heap->GetKey(minValuePoint), minValueData});

        for (int i =0; i < directs.size(); i++)
        {
            auto *nextPoint = new MazePoint(minValuePoint.X + directs[i][0], minValuePoint.Y + directs[i][1]);
            if (nextPoint->Y < this->MazeData.size() && nextPoint->X < this->MazeData[0].size())
            {
                if (nextPoint->Equals(*endPoint))
                {
                    lastData = minValueData;
                    endData = new AStarData(*endPoint, minValueData->G + 1, 0);
                    endData->Parent = lastData;
                    isFinish = true;
                    break;
                }

                //如果点在已访问列表中， 跳过
                auto result = closedIndex.find(heap->GetKey((*nextPoint)));
                if (result != closedIndex.end())
                {
                    continue;
                }

                if (this->MazeData[nextPoint->Y][nextPoint->X] == 2)
                {
                    continue;
                }

                AStarData *inQueueData = heap->Find(*nextPoint);
                if (inQueueData != NULL)
                {
                    if (inQueueData->G > minValueData->G + 1)
                    {
                        inQueueData->G = minValueData->G + 1;
                        inQueueData->Parent = minValueData;
                    }
                }
                else
                {
                    GLfloat h;
                    switch (type)
                    {
                        case RED:
                            h = hManhattanDistance(*nextPoint, *endPoint);
                            break;
                        case PINK:
                            h = hPowEuclidianDistance(*nextPoint, *endPoint);
                            break;
                        default:
                            h = hEuclidianDistance(*nextPoint, *endPoint);
                            break;
                    }

                    AStarData *nextData = new AStarData(*nextPoint, minValueData->G + 1, h);
                    nextData->Parent = minValueData;
                    heap->Add(*nextData);
                }
            }
        }
    }

    AStarData *pathData = endData;

    while (pathData->Parent->Parent != nullptr)
    {
        pathData = pathData->Parent;
    }

    if (pathData->Point.X > pathData->Parent->Point.X)
    {
        return RIGHT;
    }
    if (pathData->Point.X < pathData->Parent->Point.X)
    {
        return LEFT;
    }

    if (pathData->Point.Y > pathData->Parent->Point.Y)
    {
        return DOWN;
    }

    if (pathData->Point.Y < pathData->Parent->Point.Y)
    {
        return UP;
    }
}

GLfloat hManhattanDistance(MazePoint &point, MazePoint &endPoint)
{
    int pX = (int) point.X;
    int pY = (int) point.Y;
    int eX = (int) endPoint.X;
    int eY = (int) endPoint.Y;

    return std::abs(pX - eX) + std::abs(pY - eY);
}

GLfloat hEuclidianDistance(MazePoint &point, MazePoint &endPoint)
{
    int pX = (int) point.X;
    int pY = (int) point.Y;
    int eX = (int) endPoint.X;
    int eY = (int) endPoint.Y;

    return std::sqrt(std::pow(pX - eX, 2) + std::pow(pY - eY, 2));
}

GLfloat hPowEuclidianDistance(MazePoint &point, MazePoint &endPoint)
{
    int pX = (int) point.X;
    int pY = (int) point.Y;
    int eX = (int) endPoint.X;
    int eY = (int) endPoint.Y;

    return std::pow(pX - eX, 2) + std::pow(pY - eY, 2);
}

void Maze::GhostSwerve(Ghost &ghost)
{
    MazePoint *ghostP = this->GetMazePoint(ghost);
    Direction oppD;

    switch(ghost.Dir)
    {
        case UP:
            oppD = DOWN;
            break;
        case DOWN:
            oppD = UP;
            break;
        case LEFT:
            oppD = RIGHT;
            break;
        case RIGHT:
            oppD = LEFT;
            break;
    }

    //找到要转弯的方向
    std::vector <std::vector <int> > directs = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

    if (ghostP->X == 0 || ghostP->X == this->column)
    {
        ghost.NextDir = oppD;
        return;
    }

    std::vector <Direction> validDir;
    for (int i = 0; i < directs.size(); i++)
    {
        if (this->MazeData[ghostP->Y + directs[i][1]][ghostP->X + directs[i][0]] != 2)
        {
            if (this->MazeData[ghostP->Y + directs[i][1]][ghostP->X + directs[i][0]] == 3 && (Direction)i == DOWN)
            {
                continue;
            }

            validDir.push_back((Direction)i);
            if ((Direction)i != oppD)
            {
                ghost.NextDir = (Direction)i;
                break;
            }
        }

    }

    //如果只有一个方向， 选择
    if (validDir.size() == 1) {
        ghost.NextDir = validDir[0];
        return;
    }

    //不走重复路
    for(auto &d : validDir)
    {
        if (d != oppD)
        {
            ghost.NextDir = d;
            return;
        }
    }
}

