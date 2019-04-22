#pragma once

#include "wall.h"
#include "snake.h"
#include "apple.h"



class World
{
    friend class Game;

public:
    World() = default;
    virtual ~World() = default;

    void Create();

    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    void HandleCollisions();
  //  sf::Vector2f FindRandomFreeCell();

    Snake snake_;
    Apple apple_;
    std::vector<Wall> walls_;
};

