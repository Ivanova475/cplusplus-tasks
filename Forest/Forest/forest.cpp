#include "forest.h"


const int fire_time = 3;
const int health_points_time = 5;
const int grow_time = 2;

const int tree_state = 0;
const int burn_state = 1;
const int grow_state = 2;


Forest::Forest(const size_t height, const size_t width) : forest_(height, width)
{
    Tree new_tree;
    new_tree.curr_state = burn_state;
    new_tree.elapsed_time = health_points_time;
    forest_.SetValue(height / 2 - 1, width / 2 - 1, new_tree);
}


int Forest::CountBurnTreeAround(const size_t height_index, const size_t width_index) const
{
    int burn_around = 0;
    const int height = int(forest_.GetHeight());
    const int width = int(forest_.GetWidth());
    const int x = int(height_index);
    const int y = int(width_index);

    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if ((i < 0) || (i >= height) || (j < 0) || (j >= width) || ((i == x) && (j == y)))
            {
                continue;

            }
            else
            {
                if (forest_.GetValue(i, j).curr_state == burn_state)
                {
                    ++burn_around;
                }
            }
        }
    }

    return burn_around;
}


void Forest::ForestUpdate()
{
    const size_t height = forest_.GetHeight();
    const size_t width = forest_.GetWidth();
    Forest curr_forest = *this;
    Tree new_tree;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (curr_forest.forest_.GetValue(i, j).curr_state == burn_state)
            {
                new_tree.curr_state = burn_state;
                new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time - 1;
                curr_forest.forest_.SetValue(i, j, new_tree);
                if (curr_forest.forest_.GetValue(i, j).elapsed_time > 0)
                {
                    new_tree.curr_state = burn_state;
                    new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time;
                    forest_.SetValue(i, j, new_tree);

                } else
                {
                    new_tree.curr_state = grow_state;
                    new_tree.elapsed_time = grow_time;
                    forest_.SetValue(i, j, new_tree);
                }
            } else if (curr_forest.forest_.GetValue(i, j).curr_state == grow_state)
            {
                new_tree.curr_state = grow_state;
                new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time - 1;
                curr_forest.forest_.SetValue(i, j, new_tree);
                if (curr_forest.forest_.GetValue(i, j).elapsed_time > 0)
                {
                    new_tree.curr_state = grow_state;
                    new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time;
                    forest_.SetValue(i, j, new_tree);

                } else
                {
                    new_tree.curr_state = tree_state;
                    new_tree.elapsed_time = fire_time;
                    forest_.SetValue(i, j, new_tree);
                }
            } else if (curr_forest.forest_.GetValue(i, j).curr_state == tree_state)
            {
                new_tree.curr_state = tree_state;
                new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time - curr_forest.CountBurnTreeAround(i, j);
                curr_forest.forest_.SetValue(i, j, new_tree);
                if (curr_forest.forest_.GetValue(i, j).elapsed_time > 0)
                {
                    new_tree.curr_state = tree_state;
                    new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time;
                    forest_.SetValue(i, j, new_tree);

                } else
                {
                    new_tree.curr_state = burn_state;
                    new_tree.elapsed_time = health_points_time;
                    forest_.SetValue(i, j, new_tree);
                }
            }
        }
    }
}


std::ostream& operator << (std::ostream& output_stream, const Forest& forest)
{
    for (size_t y = 0; y < forest.forest_.GetHeight(); y++)
    {
        for (size_t x = 0; x < forest.forest_.GetWidth(); x++)
        {
            if (forest.forest_.GetValue(y, x).curr_state == burn_state)
            {
                output_stream << '*';

            } else if (forest.forest_.GetValue(y, x).curr_state == tree_state)
            {
                output_stream << '|';

            } else if (forest.forest_.GetValue(y, x).curr_state == grow_state)
            {
                output_stream << ' ';
            }
        }
        output_stream << "\n";
    }

    return  output_stream;
}
