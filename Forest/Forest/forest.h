#pragma once

#include <iostream>
#include <ostream>

#include "matrix.h"


const int fire_time = 3;
const int health_points = 5;
const int grow_time = 2;

const int tree = 0;
const int burn = 1;
const int grow = 2;


class Forest
{
    friend std::ostream& operator << (std::ostream& output_stream, const Forest& forest);

public:
    Forest(const size_t height, const size_t width);
    Forest() = default;
    virtual ~Forest() = default;

    void ForestUpdate();

    int CountBurnTreeAround(const size_t height_index, const size_t width_index) const;

private:
    Matrix forest_;
};


std::ostream& operator << (std::ostream& output_stream, const Forest& forest);
