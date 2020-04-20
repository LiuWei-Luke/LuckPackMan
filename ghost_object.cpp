#include <iostream>
#include "ghost_object.h"

GhostObject::GhostObject()
  : Position(0, 0), Size(1, 1), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(){}

GhostObject::GhostObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity)
  : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), Dir(LEFT), NextDir(LEFT){}

GhostObject::~GhostObject(){};

void GhostObject::Draw(SpriteRenderer &renderer)
{
  renderer.Sprite2D_Draw(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}

glm::vec2 GhostObject::Move(GLfloat dt, GLuint window_width)
{
    // Move the ball
    this->Position += this->Velocity * 0.1f;
    // this->Position += this->Velocity * dt;
    // Then check if outside window bounds and if so, reverse velocity and restore at correct position
    if (this->Position.x < (0.0f - this->Size.x/2))
    {
        this->Position.x = (window_width - this->Size.x/2);
    }
    else if (this->Position.x + (this->Size.x/2) > window_width)
    {
        this->Position.x = this->Size.x/2;
    }

    return this->Position;    
}