#include "maze_object.h"
#include <iostream>

MazeObject::MazeObject()
    : Position(0, 0), Size(1, 1), Color(1.0f), IsSolid(GL_TRUE), IsBit(GL_FALSE), IsBean(GL_FALSE), Rotation(0.0f), Sprite()
{
}

MazeObject::MazeObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color)
    : Position(pos), Size(size), Color(color), IsSolid(GL_TRUE), IsBit(GL_FALSE), IsBean(GL_FALSE), Rotation(0.0f), Sprite(sprite)
{

}

void MazeObject::Draw(SpriteRenderer &renderer)
{
  renderer.Sprite2D_Draw(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}
