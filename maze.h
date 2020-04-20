#ifndef MAZE_H
#define MAZE_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "maze_object.h"
#include "maze_point.h"
#include "ghost_object.h"
#include "ghost.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

class Maze
{
public:
    std::vector<MazeObject> Elements;
    std::vector <std::vector <GLuint> > MazeData;
    GLfloat UnitWidth, UnitHeight;
    GLuint row, column;
    std::vector <std::vector <GLuint> > CornerData =
        {
//            {1, 1}, {5, 1}, {10, 1}, {12, 1}, {17, 1}, {21, 1},
//            {1, 3}, {5, 3}, {7, 3}, {10, 3}, {12, 3}, {15, 3}, {17, 3}, {21, 3},
//            {1, 5}, {5, 5}, {7, 5}, {10, 5}, {12, 5}, {15, 5}, {17, 5}, {21, 5},
//            {7, 7}, {10, 7}, {12, 7}, {15, 7},
//            {5, 9}, {7, 9}, {15, 9}, {17, 9},
//            {7, 11}, {15, 11},
//            {1, 13}, {5, 13}, {7, 13}, {10, 13}, {12, 13}, {15, 13}, {17, 13}, {21, 13},
//            {1, 15}, {5, 15}, {5, 15}, {7, 15}, {10, 15}, {12, 15}, {15, 15}, {17, 15}, {19, 15}, {21, 15},
//            {1, 17}, {3, 17}, {5, 17}, {7, 17}, {10, 17}, {12, 17}, {15, 17}, {17, 17}, {19, 17}, {21, 17},
//            {1, 19}, {10, 19}, {12, 19}, {21, 19}
            {5, 1}, {17, 1},
            {1, 3}, {5, 3}, {7, 3}, {10, 3}, {12, 3}, {15, 3}, {17, 3}, {21, 3},
            {5, 5}, {17, 5},
            {10, 7}, {11,7}, {12, 7},
            {5, 9}, {7, 9}, {15, 9}, {17, 9},
            {7, 11}, {15, 11},
            {5, 13}, {7, 13}, {15, 13}, {17, 13},
            {5, 15}, {7, 15}, {10, 15}, {12, 15}, {15, 15}, {17, 15},
            {3, 17}, {19, 17},
            {10, 19}, {12, 19},
        };

    Maze(){};

    void Load(const GLchar *file, GLuint mazeWidth, GLuint mazeHeight);

    void Draw(SpriteRenderer &renderer);

    MazePoint *GetMazePoint(GhostObject &ghost);

    bool InCorner(GhostObject &ghost);

    Direction Search(MazePoint *startPoint, MazePoint *endPoint, GhostType type=RED);

    void GhostSwerve(Ghost &ghost);

    GLboolean IsCompleted();
private:
    void init(std::vector <std::vector <GLuint> > elementData,  GLuint mazeWidth, GLuint mazeHeight);
};

#endif