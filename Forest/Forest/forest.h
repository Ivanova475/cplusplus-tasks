#pragma once

#include <iostream>
#include <ostream>

#include "matrix.h"


class Forest
{
    friend std::ostream& operator << (std::ostream& output_stream, const Forest& forest);

public:
    Forest(const size_t height, const size_t width);
    virtual ~Forest() = default;

    void Update();

private:
    int CountBurnTreeAround(const size_t height_index, const size_t width_index) const;

    Matrix forest_;
};


std::ostream& operator << (std::ostream& output_stream, const Forest& forest);
