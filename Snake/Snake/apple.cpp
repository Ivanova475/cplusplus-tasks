#include "apple.h"

extern const float BLOCK_SIZE;



void Apple::Create(const sf::Vector2i& new_position)
{
    position_ = new_position;
}



sf::Vector2i Apple::GetPosition() const
{
     return position_;
}



void Apple::Update(const float dt)
{
    //Здесь ничего не нужно 
}



void Apple::Render(sf::RenderWindow& window)
{
    shape_.setRadius(BLOCK_SIZE / 2.0f);
    shape_.setPosition(sf::Vector2f(
        position_.x * BLOCK_SIZE, position_.y * BLOCK_SIZE
    ));

    shape_.setFillColor(sf::Color::Red);
    window.draw(shape_);
}

