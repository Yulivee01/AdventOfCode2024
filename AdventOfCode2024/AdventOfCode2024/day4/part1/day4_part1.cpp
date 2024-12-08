#include "day4_part1.h"

auto search_around_x(const ptrdiff_t i0, const ptrdiff_t j0, const std::vector<std::string>& input)
{
    const auto in_len = std::ssize(input);
    const auto ip1 = i0 + 1;
    const auto ip2 = i0 + 2;
    const auto ip3 = i0 + 3;
    const auto im1 = i0 - 1;
    const auto im2 = i0 - 2;
    const auto im3 = i0 - 3;

    const auto str_len = std::ssize(input[i0]);
    const auto jp1 = j0 + 1;
    const auto jp2 = j0 + 2;
    const auto jp3 = j0 + 3;
    const auto jm1 = j0 - 1;
    const auto jm2 = j0 - 2;
    const auto jm3 = j0 - 3;

    int count = 0;
    if (i0 > 2) count += std::string{ input[i0][j0], input[im1][j0], input[im2][j0], input[im3][j0] }.contains("XMAS");
    if (j0 > 2) count += std::string{ input[i0][j0], input[i0][jm1], input[i0][jm2], input[i0][jm3] }.contains("XMAS");
    if ((i0 > 2) && (j0 > 2)) count += std::string{ input[i0][j0], input[im1][jm1], input[im2][jm2], input[im3][jm3] }.contains("XMAS");
    if (i0 < in_len - 3) count += std::string{ input[i0][j0], input[ip1][j0], input[ip2][j0], input[ip3][j0] }.contains("XMAS");
    if (j0 < str_len - 3) count += std::string{ input[i0][j0], input[i0][jp1], input[i0][jp2], input[i0][jp3] }.contains("XMAS");
    if ((i0 < in_len - 3) && (j0 < str_len - 3)) count += std::string{ input[i0][j0], input[ip1][jp1], input[ip2][jp2], input[ip3][jp3] }.contains("XMAS");
    if ((i0 < in_len - 3) && (j0 > 2)) count += std::string{ input[i0][j0], input[ip1][jm1], input[ip2][jm2], input[ip3][jm3] }.contains("XMAS");
    if ((i0 > 2) && (j0 < str_len - 3)) count += std::string{ input[i0][j0], input[im1][jp1], input[im2][jp2], input[im3][jp3] }.contains("XMAS");

    return count;
}

int count_xmas(const std::vector<std::string>& input)
{
    int count = 0;
    for (ptrdiff_t i = 0; i < std::ssize(input); ++i)
    {
        for (ptrdiff_t j = 0; j < std::ssize(input[i]); ++j)
        {
            if (input[i][j] == 'X')
            {
                count += search_around_x(i, j, input);
            }
        }
    }

    return count;
}