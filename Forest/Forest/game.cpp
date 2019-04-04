#include "game.h"

const int forest_height = 30;
const int forest_width = 30;
const float rect_size = 20.0f;
const float window_height =  rect_size * (forest_height + 1);
const float window_width = rect_size * (forest_width + 1);

extern const int tree_state;
extern const int burn_state;
extern const int grow_state;


Game::Game()
	: main_window_("Forest", sf::Vector2u(window_height, window_width)),
	game_forest_(forest_height, forest_width)
{
	const sf::Vector2f size_of_rect(rect_size, rect_size);
	
	tree_.setFillColor(sf::Color::White);
	tree_.setOrigin(sf::Vector2f(size_of_rect.x / 2.0f, size_of_rect.y / 2.0f));
	tree_.setSize(sf::Vector2f(size_of_rect.x, size_of_rect.y));

	fire_.setFillColor(sf::Color::White);
	fire_.setOrigin(sf::Vector2f(size_of_rect.x / 2.0f, size_of_rect.y / 2.0f));
	fire_.setSize(sf::Vector2f(size_of_rect.x, size_of_rect.y));

	grow_.setFillColor(sf::Color::White);
	grow_.setOrigin(sf::Vector2f(size_of_rect.x / 2.0f, size_of_rect.y / 2.0f));
	grow_.setSize(sf::Vector2f(size_of_rect.x, size_of_rect.y));

	tree_texture_.loadFromFile("../data/tree.png");
	tree_texture_.setSmooth(true);

	fire_texture_.loadFromFile("../data/burn.png");
	fire_texture_.setSmooth(true);

	grow_texture_.loadFromFile("../data/grow.png");
	grow_texture_.setSmooth(true);

	tree_.setTexture(&tree_texture_);
	fire_.setTexture(&fire_texture_);
	grow_.setTexture(&grow_texture_);
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

	for (size_t y = 0; y < forest_height; y++)
	{
		for (size_t x = 0; x < forest_width; x++)
		{
			if (game_forest_.GetValue(x, y).curr_state == burn_state)
			{
				fire_.setPosition(sf::Vector2f((1 + x) * rect_size, (1 + y) * rect_size));
				main_window_.Draw(fire_);
			}
			else if (game_forest_.GetValue(x, y).curr_state == tree_state)
			{
				tree_.setPosition(sf::Vector2f((1 + x) * rect_size, (1 + y) * rect_size));
				main_window_.Draw(tree_);
			}
			else if (game_forest_.GetValue(x, y).curr_state == grow_state)
			{
				grow_.setPosition(sf::Vector2f((1 + x) * rect_size, (1 + y) * rect_size));
				main_window_.Draw(grow_);
			}
		}
	}

	main_window_.EndDraw();
}



