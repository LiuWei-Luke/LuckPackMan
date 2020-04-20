#include <iostream>
#include <tuple>
#include "game.h"
#include "sprite_renderer.h"
#include "resource_manager.h"
#include "shader.h"
#include "texture.h"

SpriteRenderer *Renderer;
GhostObject *PacMan;
Ghost *RedGhost;
Ghost *PinkGhost;

Game::Game(GLuint width, GLuint height)
    : State(GAME_PAUSE), Height(height), Width(width), Keys(), Maze(), GhostPattern(SCATTER)
{
    this->Timer = Timers[this->GhostPattern];
}

Game::~Game()
{
    delete Renderer;
    delete PacMan;
    delete RedGhost;
    delete PinkGhost;
}

void Game::Init()
{
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), 
        static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::LoadShader("../shaders/sprite.vs", "../shaders/sprite.fs", nullptr, "sprite");
    ResourceManager::GetShader("sprite").Use();
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    ResourceManager::LoadTexture("../textures/pill.png", GL_TRUE, "pill");
    ResourceManager::LoadTexture("../textures/block_solid.png", GL_FALSE, "block_solid");
    ResourceManager::LoadTexture("../textures/awesome.png", GL_TRUE, "awesome");
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    
    this->Maze.Load("../maze/maze.lvl", this->Width, this->Height);

    //load player
    GLfloat unit_width = this->Maze.UnitWidth;
    GLfloat unit_height = this->Maze.UnitHeight;
    glm::vec2 playerPos = glm::vec2(
        this->Width/2 - unit_width/2,
        unit_height * 15
    );
    PacMan = new GhostObject(playerPos, glm::vec2(unit_width, unit_height),  ResourceManager::GetTexture("awesome"));

    glm::vec2 RedGhostPos = glm::vec2(
            this->Width/2 - unit_width/2,
            unit_height * 7
    );
    //load Ghost
    MazePoint *topRight = new MazePoint(19, 1);
    RedGhost = new Ghost(RedGhostPos, glm::vec2(unit_width, unit_height), 1, ResourceManager::GetTexture("awesome"), RED, *topRight);

    RedGhost->State = SCATTER;
    RedGhost->Dir = LEFT;


    glm::vec2 PinkGhostPos = glm::vec2(
            unit_width * 13,
            unit_height * 9
    );
    MazePoint *topLeft = new MazePoint(2, 1);
    PinkGhost = new Ghost(PinkGhostPos, glm::vec2(unit_width, unit_height), 1, ResourceManager::GetTexture("awesome"), PINK, *topLeft);

    PinkGhost->State = IMPRISON;
    PinkGhost->Dir = UP;
    PinkGhost->NextDir = DOWN;

    this->Ghosts.push_back(RedGhost);
    this->Ghosts.push_back(PinkGhost);
}

void Game::Update(GLfloat dt)
{
    this->UpdateGhostsParttern(dt);
    PacMan->Move(dt, this->Width);

    this->Swerve(*PacMan);
    this->UpdateVelocity(*PacMan);
    this->UpdateTexture(*PacMan);

    this->UpdateGhostsDir();

    for (auto &ghost: this->Ghosts)
    {
        ghost->Move(dt, this->Width);

        //更新坐标
         MazePoint *gPoint = this->Maze.GetMazePoint(*ghost);

        //处理复活
        MazePoint *resurgenceP = new MazePoint(11, 7);
        if (gPoint->Equals(*resurgenceP) && ghost->State == ESCAPE)
        {
            ghost->Resurgence();
        }
    }


    this->DoCollision();
    this->DoChased();
}

void::Game::UpdateGhostsDir()
{
    MazePoint *PacPoint = this->Maze.GetMazePoint(*PacMan);
    for (auto &ghost : this->Ghosts)
    {
        MazePoint *ghostP = this->Maze.GetMazePoint(*ghost);
        ghost->NowPoint = ghostP;

        if (ghost->State == IMPRISON)
        {
            ghost->NextDir = ghost->GetOppsiteDir(ghost->Dir);
            continue;
        }


        if (this->Maze.InCorner(*ghost))
        {
            if (ghost->LastPoint == nullptr || !ghost->NowPoint->Equals(*ghost->LastPoint))
            {
                MazePoint *startPoint = this->Maze.GetMazePoint(*ghost);
                Direction latestDir;

                switch (ghost->State)
                {

                    case SCATTER:
                        latestDir = this->Maze.Search(ghostP, &ghost->TargetPoint, ghost->Type);
                        break;
                    case CHASE:
                        latestDir = this->Maze.Search(ghostP, PacPoint);
                        break;
                    case ESCAPE:
                        latestDir = this->Maze.Search(ghostP, &ghost->EscapePoint);
                        break;
                    case FRIGHTEN:
                        latestDir = this->Maze.Search(ghostP, &ghost->EscapePoint, RED);
                        break;
                }

                if (ghost->GetOppsiteDir(ghost->Dir) != latestDir)
                {
                    ghost->NextDir = latestDir;
                } else {
                    this->Maze.GhostSwerve(*ghost);
                }

                ghost->UpdateCoordinate(ghostP);
            }
        } else {
            this->Maze.GhostSwerve(*ghost);
            ghost->UpdateCoordinate(ghostP);
        }

        this->Swerve(*ghost);
        this->UpdateVelocity(*ghost);
    }
}

void Game::ProcessInput(GLfloat dt)
{
    if (this->State == GAME_ACTIVE) 
    {
        if (this->Keys[GLFW_KEY_A])
        {
            PacMan->NextDir = LEFT;
        }
        if (this->Keys[GLFW_KEY_D])
        {
            PacMan->NextDir = RIGHT;
        }
        if (this->Keys[GLFW_KEY_W])
        {
            PacMan->NextDir = UP;
        }
        if (this->Keys[GLFW_KEY_S])
        {
            PacMan->NextDir = DOWN;
        }
    }    
}

void Game::Render()
{
    if(this->State == GAME_ACTIVE) {
        this->Maze.Draw(*Renderer);
        PacMan->Draw(*Renderer);
        RedGhost->Draw(*Renderer);
        PinkGhost->Draw(*Renderer);
    }
}

void Game::UpdateVelocity(GhostObject &ghost)
{
    if (ghost.Dir == LEFT)
    {
        ghost.Velocity.x = -ghost.MoveVelocity;
        ghost.Velocity.y = 0;
    }
    if (ghost.Dir == RIGHT)
    {
        ghost.Velocity.x = ghost.MoveVelocity;
        ghost.Velocity.y = 0;
    }
    if (ghost.Dir == UP)
    {
        ghost.Velocity.y = -ghost.MoveVelocity;
        ghost.Velocity.x = 0;
    }
    if (ghost.Dir == DOWN)
    {
        ghost.Velocity.y = ghost.MoveVelocity;
        ghost.Velocity.x = 0;
    }
}


void Game::UpdateTexture(GhostObject &ghost)
{
    if (ghost.Dir == LEFT)
    {
        ghost.Rotation = glm::radians(0.0f);
    }
    if (ghost.Dir == RIGHT)
    {
        ghost.Rotation = glm::radians(180.0f);
    }
    if (ghost.Dir == UP)
    {
        ghost.Rotation = glm::radians(90.0f);
    }
    if (ghost.Dir == DOWN)
    {
        ghost.Rotation = glm::radians(-90.0f);
    }    
}

GLboolean CheckCollision(GhostObject &one, MazeObject &two);
GLboolean CheckChased(GhostObject &one, Ghost &two);
GLboolean CheckBit(GhostObject &one, MazeObject &two);

void Game::Swerve(GhostObject &ghost)
{
    Direction nextDir = ghost.NextDir;
    if (nextDir == LEFT)
    {
        ghost.Position.x -= 1.0f;
    }
    if (nextDir == RIGHT)
    {
        ghost.Position.x += 1.0f;
    }
    if (nextDir == UP)
    {
        ghost.Position.y -= 1.0f;
    }
    if (nextDir == DOWN)
    {
        ghost.Position.y += 1.0f;
    }

    GLboolean noCol = GL_TRUE;
    for(MazeObject &tail : this->Maze.Elements)
    {
        if (tail.IsSolid)
        {
            if(CheckCollision(ghost, tail))
            {
                noCol = GL_FALSE;
                break;
            }
        }            
    }

    if (noCol) {
        ghost.Dir = nextDir;
    }

    if (nextDir == LEFT)
    {
        ghost.Position.x += 1.0f;
    }
    if (nextDir == RIGHT)
    {
        ghost.Position.x -= 1.0f;
    }
    if (nextDir == UP)
    {
        ghost.Position.y += 1.0f;
    }
    if (nextDir == DOWN)
    {
        ghost.Position.y -= 1.0f;
    }  
}

// Direction VectorDirection(glm::vec2 closest)

void Game::DoCollision()
{
    std::vector<GhostObject*> movingGhosts;
    movingGhosts.push_back(PacMan);
    movingGhosts.push_back(RedGhost);
    movingGhosts.push_back(PinkGhost);

    for(MazeObject &tail : this->Maze.Elements)
    {
        if (tail.IsSolid) {
            for (auto ghost : movingGhosts)
            {
                if (CheckCollision(*ghost, tail))
                {
                    Direction dir = ghost->Dir;
                    if (dir == LEFT)
                    {
                        ghost->Velocity.x = 0.0f;
                        ghost->Position.x = tail.Position.x + tail.Size.x; // 将球右移
                    }
                    if (dir == RIGHT)
                    {
                        ghost->Velocity.x = 0.0f;
                        ghost->Position.x = tail.Position.x - ghost->Size.x; // 将球右移
                    }
                    if (dir == UP)
                    {
                        ghost->Velocity.y = 0.0f;
                        ghost->Position.y = tail.Position.y + ghost->Size.y; // 将球右移
                    }
                    if (dir == DOWN)
                    {
                        ghost->Velocity.y = 0.0f;
                        ghost->Position.y = tail.Position.y - ghost->Size.y; // 将球右移
                    }
                }
            }
        }
        if (tail.IsBean && !tail.IsBit && !tail.IsPower)
        {
            if (CheckBit(*PacMan, tail))
            {
                tail.IsBit = GL_TRUE;
            }
        }

        if (tail.IsBean && !tail.IsBit && tail.IsPower)
        {
            if (CheckBit(*PacMan, tail))
            {
                tail.IsBit = GL_TRUE;

                //DO FRIGHTEN
                this->FrightGhosts();
            }
        }

    }
}

void Game::DoChased()
{
    for (auto &ghost : this->Ghosts)
    {
        if (CheckChased(*PacMan, *ghost))
        {
            if (ghost->State == CHASE || ghost->State == SCATTER)
            {
                std::cout << "YOU DIE" << std::endl;
            } else if (ghost->State == FRIGHTEN){
                ghost->NextDir = this->Maze.Search(ghost->NowPoint, &ghost->EscapePoint, RED);
                ghost->BePaced();
            } else {
                std::cout << "Nothing" << std::endl;
            }
        }
    }
}

void Game::UpdateGhostsParttern(GLfloat dt)
{
    this->Timer -= dt;

    for (auto &i : this->Ghosts)
    {
        if (i->FrightenTimer > 0)
        {
            i->FrightenTimer -= dt;
        }

        if (i->ImprisonTimer > 0)
        {
            i->ImprisonTimer -= dt;
        }

        if (i->State == FRIGHTEN && i->FrightenTimer <= 0.0f)
        {
            i->State = this->GhostPattern;
            i->MoveVelocity = RED_GHOST_VELOCITY;
        }

        if (i->State == IMPRISON && i->ImprisonTimer <= 0.0f)
        {
            i->State = this->GhostPattern;
            i->MoveVelocity = RED_GHOST_VELOCITY;
        }
    }

    if (this->Timer > 0.0f)
    {
        return;
    }

    if (this->GhostPattern == SCATTER)
    {
        this->Timer = this->Timers[CHASE];
        this->GhostPattern = CHASE;
        for (auto &i : this->Ghosts)
        {
            if (i->State == SCATTER) {
                i->State = CHASE;
            }
        }
        return;
    }

    if (this->GhostPattern == CHASE)
    {
        this->Timer = this->Timers[SCATTER];
        for (auto &i : this->Ghosts)
        {
            if (i->State == CHASE) {
                i->State = SCATTER;
            }
        }
        this->GhostPattern = SCATTER;
        return;
    }

//    if (this->GhostPattern == FRIGHTEN)
//    {
//        this->Timer = this->Timers[CHASE];
//        for (auto &i : this->Ghosts)
//        {
//            if (i->State != IMPRISON) {
//                i->State = SCATTER;
//            }
//            i->State = CHASE;
//            i->MoveVelocity = RED_GHOST_VELOCITY;
//        }
//        this->GhostPattern = CHASE;
//        return;
//    }
}

void Game::FrightGhosts()
{
//    this->GhostPattern = FRIGHTEN;
    for (auto &ghost : this->Ghosts)
    {
        ghost->FrightenTimer = this->Timers[FRIGHTEN];
        Direction latestDir;
        MazePoint *ghostP = this->Maze.GetMazePoint(*ghost);
        latestDir = this->Maze.Search(ghostP, &ghost->EscapePoint);

        ghost->NextDir = latestDir;

        ghost->UpdateCoordinate(ghostP);
        ghost->BeFrighten();
    }
}

GLboolean CheckCollision(GhostObject &one, MazeObject &two)
{
    // x轴方向碰撞？
    bool collisionX = one.Position.x + one.Size.x > two.Position.x &&
        two.Position.x + two.Size.x > one.Position.x;
    // y轴方向碰撞？
    bool collisionY = one.Position.y + one.Size.y > two.Position.y &&
        two.Position.y + two.Size.y > one.Position.y;
    // 只有两个轴向都有碰撞时才碰撞


    return collisionX && collisionY;
}

GLboolean CheckChased(GhostObject &one, Ghost &two)
{
    // x轴方向碰撞？
    bool collisionX = one.Position.x + one.Size.x > two.Position.x &&
                      two.Position.x + two.Size.x > one.Position.x;
    // y轴方向碰撞？
    bool collisionY = one.Position.y + one.Size.y > two.Position.y &&
                      two.Position.y + two.Size.y > one.Position.y;
    // 只有两个轴向都有碰撞时才碰撞


    return collisionX && collisionY;
}

GLboolean CheckBit(GhostObject &one, MazeObject &two)
{
    // x轴方向碰撞？
    bool collisionX = one.Position.x + one.Size.x > two.Position.x + 15.0f &&
        two.Position.x + two.Size.x > one.Position.x;
    // y轴方向碰撞？
    bool collisionY = one.Position.y + one.Size.y > two.Position.y + 15.0f &&
        two.Position.y + two.Size.y > one.Position.y;
    // 只有两个轴向都有碰撞时才碰撞

    return collisionX && collisionY;    
}