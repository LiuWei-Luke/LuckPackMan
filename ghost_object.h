#ifndef GHOST_OBJECT_H
#define GHOST_OBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "sprite_renderer.h"
#include "texture.h"

const GLfloat PAC_VELOCITY(25.0f);
const GLfloat RED_GHOST_VELOCITY(20.0f);

enum Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class GhostObject
{
public:
    glm::vec2 Position, Size, Velocity;
    glm::vec3 Color;
    GLfloat   Rotation;    
    Texture2D Sprite;
    Direction Dir;
    GLboolean Moving;
    Direction NextDir;
    GLfloat MoveVelocity = PAC_VELOCITY;
    // Constructor(s)
    GhostObject();
    GhostObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite,
      glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
    virtual ~GhostObject();

    glm::vec2 Move(GLfloat dt, GLuint window_width);
    virtual void Draw(SpriteRenderer &renderer);

};

#endif