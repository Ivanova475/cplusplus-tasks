#pragma once

#include <iostream>
#include <ostream>
#include <SFML/Graphics.hpp>

#include "matrix.h"


class Forest
{
    friend std::ostream& operator << (std::ostream& output_stream,
        const Forest& forest);

public:
    Forest(const size_t height, const size_t width,
        const double rect_size);
    virtual ~Forest() = default;

    void Update();
    void Render(sf::RenderWindow& window);

    Tree GetValue(const size_t height_index,
        const size_t width_index);

private:
    int CountBurnTreeAround(const size_t height_index,
        const size_t width_index) const;

    Matrix forest_;

    sf::RectangleShape tree_;
    sf::RectangleShape fire_;
    sf::RectangleShape grow_;

    sf::Texture tree_texture_;
    sf::Texture fire_texture_;
    sf::Texture grow_texture_;

    const double rect_size_;
};


std::ostream& operator << (std::ostream& output_stream,
    const Forest& forest);
