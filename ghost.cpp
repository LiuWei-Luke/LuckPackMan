#include <iostream>
#include "ghost.h"

Ghost::Ghost()
  : GhostObject(), Stuck(true), Level(1), TargetPoint(1, 1), EscapePoint(11, 9) {}

Ghost::Ghost(glm::vec2 pos, glm::vec2 size, GLint level, Texture2D sprite, GhostType type, MazePoint point)
  : GhostObject(pos, size, sprite, glm::vec3(1.0f), glm::vec2(0, 0)), Stuck(true), Level(level), LastPosition(pos), Type(type), TargetPoint(point)
  , EscapePoint(11, 9)
{
    switch (this->Type)
    {
        case RED:
            this->MoveVelocity = RED_GHOST_VELOCITY;
            this->Color = glm::vec3(1.0f, 0.0f, 0.0f);
            break;
        case BLUE:
            this->MoveVelocity = RED_GHOST_VELOCITY;
            this->ImprisonTimer = 9.0f;
            break;
        case PINK:
            this->MoveVelocity = RED_GHOST_VELOCITY;
            this->ImprisonTimer = 5.0f;
            this->Color = glm::vec3(0.94f, 0.62f, 0.76f);
            break;
        case ORANGE:
            this->MoveVelocity = RED_GHOST_VELOCITY;
            this->ImprisonTimer = 7.0f;
            break;
    }
}

glm::vec2 Ghost::Move(GLfloat dt, GLuint window_width)
{
    // Move the ball
    this->Position += this->Velocity * 0.1f;
    // this->Position += this->Velocity * dt;
    // Then check if outside window bounds and if so, reverse velocity and restore at correct position
    if (this->Position.x <= 0.0f)
    {
        this->Velocity.x = 0.0f;
        this->Position.x = 0.0f;
    }
    else if (this->Position.x + this->Size.x >= window_width)
    {
        this->Velocity.x = 0.0f;
        this->Position.x = window_width - this->Size.x;
    }

    return this->Position;
}

Direction Ghost::GetOppsiteDir(Direction dir)
{
    Direction dirCameFrom;
    switch(dir)
    {
        case UP:
            dirCameFrom = DOWN;
            break;
        case DOWN:
            dirCameFrom = UP;
            break;
        case LEFT:
            dirCameFrom = RIGHT;
            break;
        case RIGHT:
            dirCameFrom = LEFT;
            break;
    }

    return dirCameFrom;
}

void Ghost::BeFrighten()
{
    this->State = FRIGHTEN;
    this->MoveVelocity = FRIGHTEN_VELOCITY;
//    this->Dir = this->GetOppsiteDir(this->Dir);
//    this->NextDir = this->GetOppsiteDir(this->NextDir);
}

void Ghost::BePaced()
{
    this->State = ESCAPE;
    this->MoveVelocity = ESCAPE_VELOCITY;
}

void Ghost::Resurgence()
{
    this->State = CHASE;
    this->MoveVelocity = RED_GHOST_VELOCITY;
}

void Ghost::UpdateCoordinate(MazePoint *nowPoint)
{
    this->LastPoint = nowPoint;
}

