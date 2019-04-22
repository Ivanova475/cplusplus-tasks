#include "snake.h"

extern const float BLOCK_SIZE;



void Snake::Create(const sf::Vector2i& head_position)
{
    Segment head = {
        head_position,
        sf::RectangleShape(),
        sf::Color::Magenta
    };

    body_.push_back(std::move(head));
}



bool Snake::CheckSelfCollisison() const
{
    for (size_t i = 1; i < body_.size(); i++)
    {
         if (body_[0].position == body_[i].position)
         {
             return true;
         }
    }

    return false;
}



sf::Vector2i Snake::GetHeadPosition()
{
    assert(!body_.empty());
    return body_[0].position;
}



const std::vector<Snake::Segment>& Snake::GetBody()
{
    return body_;
}



void Snake::Update(const float dt)
{
    MoveByOneCell();
}



void Snake::Render(sf::RenderWindow& window)
{
    for (auto& body_part : body_)
    {
        body_part.shape.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
        body_part.shape.setPosition(sf::Vector2f(body_part.position.x * BLOCK_SIZE, body_part.position.y * BLOCK_SIZE));
        body_part.shape.setFillColor(body_part.color);
        window.draw(body_part.shape);
    }
}



void Snake::MoveByOneCell()
{
    for (auto it = body_.rbegin(); it + 1 != body_.rend(); it++)
    {
        it->position = (it + 1)->position;
    }
    switch (direction_)
    {
    case Snake::Up:
        --body_.begin()->position.y;
        break;
    case Snake::Right:
        ++body_.begin()->position.x;
        break;
    case Snake::Down:
        ++body_.begin()->position.y;
        break;
    case Snake::Left:
        --body_.begin()->position.x;
        break;
    case Snake::None:
        break;
    default:
        break;
    }
}



void Snake::Grow()
{
    assert(!body_.empty());
    sf::Vector2i new_tail_position;
    if (body_.size() == 1)
    {
        switch (direction_)
        {
        case Snake::Up:
            new_tail_position.x = body_[0].position.x;
            new_tail_position.y = body_[0].position.y + 1;
            break;
        case Snake::Right:
            new_tail_position.x = body_[0].position.x - 1;
            new_tail_position.y = body_[0].position.y;
            break;
        case Snake::Down:
            new_tail_position.x = body_[0].position.x;
            new_tail_position.y = body_[0].position.y - 1;
            break;
        case Snake::Left:
            new_tail_position.x = body_[0].position.x + 1;
            new_tail_position.y = body_[0].position.y;
            break;
        case Snake::None:
            break;
        default:
            break;
        }
    }
    else
    {
        auto tail = body_[body_.size() - 1];
        auto prev_tail = body_[body_.size() - 2];

        if (tail.position.x == prev_tail.position.x)
        {
            new_tail_position.x = tail.position.x;
            new_tail_position.y = tail.position.y 
                + (prev_tail.position.y - tail.position.y);
        }
        else 
        {
            new_tail_position.y = tail.position.y;
            new_tail_position.x = tail.position.x 
                + (prev_tail.position.x - tail.position.x);
        }
    }

    Segment new_tail = {
        new_tail_position,
        sf::RectangleShape(),
        sf::Color::Blue
    };

    body_.push_back(std::move(new_tail));
}



Snake::Direction Snake::GetDirection() const
{
    return direction_;
}



void Snake::SetDirection(const Snake::Direction new_direction)
{
    direction_ = new_direction;
}



int Snake::GetScore() const
{
    return score_;
}



void Snake::IncreaseScore(const int delta_score)
{
    score_ += delta_score;
}



int Snake::GetLives() const
{
    return lives_;
}



void Snake::DecreaseLivesByOne()
{
    --lives_;
}                                                              