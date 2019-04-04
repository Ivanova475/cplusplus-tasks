#include "game.h"

const int forest_height = 30;
const int forest_width = 30;
const float rect_size = 20.0f;
const float window_height =  rect_size * (forest_height + 1);
const float window_width = rect_size * (forest_width + 1);


Game::Game()
    : main_window_("Forest", sf::Vector2u(window_height, window_width)),
    game_forest_(forest_height, forest_width, rect_size)
{
    
}


void Game::Run()
{
    while (!main_window_.CheckIsDone())
    {
        //HandleInput();
        Update();
        Render();
    }
}


void Game::HandleInput()
{
    //getchar();
}


void Game::Update()
{
    main_window_.Update();
    game_forest_.Update();
}


void Game::Render()
{
    main_window_.BeginDraw();
    main_window_.Draw(game_forest_);
    main_window_.EndDraw();
}



