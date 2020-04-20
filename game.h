#ifndef GAME_H
#define GAME_H

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "maze.h"
#include "ghost_object.h"
#include "ghost.h"


enum GameState {
  GAME_ACTIVE,
  GAME_PAUSE,
  GAME_WIN,
  GAME_OVER
};



class Game
{
public:
    GameState State;
    GLuint Height, Width;
    GLboolean Keys[1024];
    std::vector <GLfloat> Timers = {7.0f, 10.0f, 15.0f};
    GLfloat Timer;
    GhostState GhostPattern;

    Maze Maze;
    std::vector<Ghost *> Ghosts;

    Game(GLuint width, GLuint height);
    ~Game();

    void Init();
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollision();
    void UpdateVelocity(GhostObject &ghost);
    void UpdateTexture(GhostObject &ghost);
    void UpdateGhostsDir();
    void Swerve(GhostObject &ghost);
    void UpdateGhostsParttern(GLfloat dt);
    void FrightGhosts();
    void DoChased();
};

#endif