#ifndef GHOST_H
#define GHOST_H 

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "texture.h"
#include "ghost_object.h"
#include "maze_point.h"

enum GhostState {
    SCATTER,
    FRIGHTEN,
    CHASE,
    ESCAPE,
    IMPRISON
};

enum GhostType {
    RED,
    PINK,
    BLUE,
    ORANGE
};

const GLfloat FRIGHTEN_VELOCITY(10.0f);
const GLfloat ESCAPE_VELOCITY(60.0f);

class Ghost : public GhostObject
{
public:
    GLfloat   Radius;
    GLboolean Stuck;
    GLint Level;
    glm::vec2 LastPosition;
    MazePoint *NowPoint;
    MazePoint *LastPoint = nullptr;
    GhostType Type;
    MazePoint TargetPoint;
    MazePoint EscapePoint;
    GLfloat FrightenTimer = 0.0f;
    GLfloat ImprisonTimer = 10.0f;
    // Constructor(s)
    Ghost();
    Ghost(glm::vec2 pos, glm::vec2 size, GLint level, Texture2D sprite, GhostType type, MazePoint point);
    // Moves the ball, keeping it constrained within the window bounds (except bottom edge); returns new position
    glm::vec2 Move(GLfloat dt, GLuint window_width);
    // Resets the ball to original state with given position and velocity
    void      Reset(glm::vec2 position, glm::vec2 velocity);
    Direction GetOppsiteDir(Direction dir);
    void UpdateCoordinate(MazePoint *);
    void BeFrighten();
    void BePaced();
    void Resurgence();

    GhostState State;
};

#endif