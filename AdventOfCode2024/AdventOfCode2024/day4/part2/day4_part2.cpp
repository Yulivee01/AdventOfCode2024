#include "day4_part2.h"

namespace
{
    auto search_around_a(const ptrdiff_t i, const ptrdiff_t j, const std::vector<std::string>& input)
    {
        int count = 0;
        const auto diagonal_left_right = std::string{ input[i - 1][j - 1], input[i][j], input[i + 1][j + 1] };
        const auto diagonal_right_left = std::string{ input[i - 1][j + 1], input[i][j], input[i + 1][j - 1] };

        if ((diagonal_left_right.contains("MAS") || diagonal_left_right.contains("SAM"))
            && (diagonal_right_left.contains("MAS") || diagonal_right_left.contains("SAM")))
        {
            ++count;
        }

        return count;
    }
}

int count_x_mas(const std::vector<std::string>& input)
{
    int count = 0;
    for (ptrdiff_t i = 1; i < std::ssize(input) - 1; ++i)
    {
        for (ptrdiff_t j = 1; j < std::ssize(input[i]) - 1; ++j)
        {
            if (input[i][j] == 'A')
            {
                count += search_around_a(i, j, input);
            }
        }
    }

    return count;
}