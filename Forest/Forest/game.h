#pragma once

#include "window.h"
#include "forest.h"


class Game
{
public:
    Game();
    virtual ~Game() = default;

    void Run();
    void HandleInput();
    void Update();
    void Render();


private:
    Window main_window_;

    sf::RectangleShape tree_;
    sf::RectangleShape fire_;
    sf::RectangleShape grow_;

    sf::Texture tree_texture_;
    sf::Texture fire_texture_;
    sf::Texture grow_texture_;

    Forest game_forest_;
};


