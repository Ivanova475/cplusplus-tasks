#pragma once

#include <vector>


struct Tree
{
    int curr_state = 0;
    int elapsed_time = 3;
};


class Matrix
{
 public:
    Matrix(const size_t height, const size_t width);
    virtual ~Matrix() = default;

    size_t GetHeight() const;
    size_t GetWidth() const;

    Tree GetValue(const size_t height_index, const size_t width_index) const;
    void SetValue(const size_t height_index, const size_t width_index, const Tree& new_tree);

private:
    std::vector<std::vector<Tree>> data_;
};



