#include "day4_part2.h"

#include <algorithm>
#include <ranges>

namespace
{
    auto search_around_a(const ptrdiff_t i, const ptrdiff_t j, const std::vector<std::string>& input)
    {
        const auto diagonal_left_right = std::string{ input[i - 1][j - 1], input[i][j], input[i + 1][j + 1] };
        const auto diagonal_right_left = std::string{ input[i - 1][j + 1], input[i][j], input[i + 1][j - 1] };

        if ((diagonal_left_right.contains("MAS") || diagonal_left_right.contains("SAM"))
            && (diagonal_right_left.contains("MAS") || diagonal_right_left.contains("SAM")))
        {
            return 1;
        }

        return 0;
    }
}

int count_x_mas(const std::vector<std::string>& input)
{
    return std::ranges::fold_left(std::views::cartesian_product(
        std::views::iota(ptrdiff_t{ 1 }, std::ssize(input) - 1),
        std::views::iota(ptrdiff_t{ 1 }, std::ssize(input.front()) - 1))
        | std::views::transform([&](const auto& coordinates)
            {
                const auto [i, j] = coordinates;
                if (input[i][j] == 'A') return search_around_a(i, j, input);
                return 0;
            }), 0, std::plus{});
}