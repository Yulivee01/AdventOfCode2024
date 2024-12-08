#include "day4_part2.h"

auto search_around_a(const ptrdiff_t i0, const ptrdiff_t j0, const std::vector<std::string>& input)
{
    const auto in_len = std::ssize(input);
    const auto ip1 = i0 + 1;
    const auto im1 = i0 - 1;

    const auto str_len = std::ssize(input[i0]);
    const auto jp1 = j0 + 1;
    const auto jm1 = j0 - 1;

    int count = 0;
    if ((std::string{ input[im1][jm1],input[i0][j0], input[ip1][jp1] }.contains("MAS") || std::string{ input[im1][jm1],input[i0][j0], input[ip1][jp1] }.contains("SAM"))
        && (std::string{ input[im1][jp1], input[i0][j0], input[ip1][jm1] }.contains("MAS") || std::string{ input[im1][jp1], input[i0][j0], input[ip1][jm1] }.contains("SAM")))
    {
        ++count;
    }

    return count;
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