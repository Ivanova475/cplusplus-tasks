#pragma once

#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include <vector>



class Snake
{
public:
    struct Segment
    {
        sf::Vector2i position;
        sf::RectangleShape shape;
        sf::Color color;
    };

    enum Direction
    {
        Up,
        Right,
        Down,
        Left,
        None
    };

public:
    Snake() = default;
    virtual ~Snake() = default;

    void Create(const sf::Vector2i& head_position);

    bool CheckSelfCollisison() const;
    void Grow();

    Direction GetDirection() const;
    void SetDirection(const Direction new_direction);
    int GetScore() const;
    void IncreaseScore(const int delta_score);
    int GetLives() const;
    void DecreaseLivesByOne();

    sf::Vector2i GetHeadPosition();
    const std::vector<Segment>& GetBody();

    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    void MoveByOneCell();

    std::vector<Segment> body_;
    Direction direction_;
    
    int lives_;
    int score_;
};

