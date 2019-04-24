#include "world.h"



void World::Create()
{
    snake_.Create(sf::Vector2i(10, 10));
    apple_.Create(sf::Vector2i(5, 5));
}



void World::Update(const float dt)
{
    snake_.Update(dt);
    apple_.Update(dt);
    
    for (Wall& wall : walls_)
    {
        wall.Update(dt);
    }

    HandleCollisions();
}



void World::HandleCollisions()
{
    if (snake_.GetBody()[0].position == apple_.GetPosition())
    {
        snake_.Grow();
        apple_.Create(sf::Vector2i(apple_.GetPosition().x + 2, apple_.GetPosition().y + 2));
    }
}



void World::Render(sf::RenderWindow& window)
{
    snake_.Render(window);
    apple_.Render(window);

    for (Wall& wall : walls_)
    {
        wall.Render(window);
    }

}



/*sf::Vector2f World::FindRandomFreeCell()
{
    
    //вызывает snake.GetBody apple.GetPosition и для всех стен формирует рандомную клетку 
    которая не лежит в теле змеи и не лежит в яблоке и проверяем что полученная клетка не принадлежит ни одной из стен

} */