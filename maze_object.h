#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "texture.h"
#include "sprite_renderer.h"

class MazeObject
{
  public:
    glm::vec2 Position, Size;
    glm::vec3 Color;
    GLboolean IsSolid;
    GLboolean IsBit;
    GLboolean IsBean;
    GLboolean IsPower;
    GLfloat   Rotation;

    Texture2D Sprite;

    MazeObject();
    MazeObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite,
      glm::vec3 color = glm::vec3(0.0f));
    
    virtual void Draw(SpriteRenderer &renderer);
};

#endif