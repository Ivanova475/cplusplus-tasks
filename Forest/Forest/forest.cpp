#include "forest.h"


Forest::Forest(const size_t height, const size_t width) : forest_(height, width)
{
    Tree new_tree;
    new_tree.curr_state = burn;
    new_tree.elapsed_time = health_points;
    forest_.SetValue(height / 2 - 1, width / 2 - 1, new_tree);
}


int Forest::CountBurnTreeAround(const size_t height_index, const size_t width_index) const
{
    int burn_around = 0;
    const size_t height = forest_.GetHeight();
    const size_t width = forest_.GetWidth();
    size_t t = 0;
    size_t k = 0;

    if ((height_index > 0) && (height_index < height - 1) && (width_index > 0) && (width_index < width - 1))
    {
        for (t = height_index - 1; t < height_index + 2; t++)
        {
            for (k = width_index - 1; k < width_index + 2; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((height_index == 0) && (width_index > 0) && (width_index < width - 1))
    {
        for (t = 0; t < height_index + 2; t++)
        {
            for (k = width_index - 1; k < width_index + 2; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((height_index == height - 1) && (width_index > 0) && (width_index < width - 1))
    {
        for (t = height_index - 1; t < height; t++)
        {
            for (k = width_index - 1; k < width_index + 2; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((width_index == 0) && (height_index > 0) && (height_index < height - 1))
    {
        for (t = height_index - 1; t < height_index + 1; t++)
        {
            for (k = 0; k < width_index + 2; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((width_index == width - 1) && (height_index > 0) && (height_index < height - 1))
    {
        for (t = height_index - 1; t < height_index + 2; t++)
        {
            for (k = width_index - 1; k < width; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((width_index == 0) && (height_index == 0))
    {
        for (t = 0; t < height_index + 2; t++)
        {
            for (k = 0; k < width_index + 2; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((width_index == 0) && (height_index == height - 1))
    {
        for (t = height_index - 1; t < height; t++)
        {
            for (k = 0; k < width_index + 2; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((width_index == width - 1) && (height_index == 0))
    {
        for (t = 0; t < height_index + 2; t++)
        {
            for (k = width_index - 1; k < width; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
                {
                    ++burn_around;
                }
            }
        }
    } else if ((width_index == width - 1) && (height_index == height - 1))
    {
        for (t = height_index - 1; t < height; t++)
        {
            for (k = width_index - 1; k < width; k++)
            {
                if (forest_.GetValue(t, k).curr_state == burn)
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
            if (curr_forest.forest_.GetValue(i, j).curr_state == burn)
            {
                new_tree.curr_state = burn;
                new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time - 1;
                curr_forest.forest_.SetValue(i, j, new_tree);
                if (curr_forest.forest_.GetValue(i, j).elapsed_time > 0)
                {
                    new_tree.curr_state = burn;
                    new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time;
                    forest_.SetValue(i, j, new_tree);
                }
                else
                {
                    new_tree.curr_state = grow;
                    new_tree.elapsed_time = grow_time;
                    forest_.SetValue(i, j, new_tree);
                }
            } else if (curr_forest.forest_.GetValue(i, j).curr_state == grow)
            {
                new_tree.curr_state = grow;
                new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time - 1;
                curr_forest.forest_.SetValue(i, j, new_tree);
                if (curr_forest.forest_.GetValue(i, j).elapsed_time > 0)
                {
                    new_tree.curr_state = grow;
                    new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time;
                    forest_.SetValue(i, j, new_tree);
                }
                else
                {
                    new_tree.curr_state = tree;
                    new_tree.elapsed_time = fire_time;
                    forest_.SetValue(i, j, new_tree);
                }
            } else if (curr_forest.forest_.GetValue(i, j).curr_state == tree)
            {
                new_tree.curr_state = tree;
                new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time - curr_forest.CountBurnTreeAround(i, j);
                curr_forest.forest_.SetValue(i, j, new_tree);
                if (curr_forest.forest_.GetValue(i, j).elapsed_time > 0)
                {
                    new_tree.curr_state = tree;
                    new_tree.elapsed_time = curr_forest.forest_.GetValue(i, j).elapsed_time;
                    forest_.SetValue(i, j, new_tree);
                }
                else
                {
                    new_tree.curr_state = burn;
                    new_tree.elapsed_time = health_points;
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
            if (forest.forest_.GetValue(y, x).curr_state == burn)
            {
                output_stream << '*';
            } else if (forest.forest_.GetValue(y, x).curr_state == tree)
            {
                output_stream << '|';
            } else if (forest.forest_.GetValue(y, x).curr_state == grow)
            {
                output_stream << ' ';
            }
        }
        output_stream << "\n";
    }

    return  output_stream;
}
