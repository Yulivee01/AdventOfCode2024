#include "day4_part1.h"

#include <algorithm>
#include <iostream>
#include <ranges>

namespace
{
    auto search_around_x(const ptrdiff_t i, const ptrdiff_t j, const std::vector<std::string>& input)
    {
        auto count = 0;

        // down
        count += (input
            | std::views::drop(i)
            | std::views::transform([&](const auto& row) {return row[j]; })
            | std::views::take(4)
            | std::ranges::to<std::string>()).contains("XMAS");

        // right
        count += (input[i]
            | std::views::drop(j)
            | std::views::take(4)
            | std::ranges::to<std::string>()).contains("XMAS");

        // down right
        if ((i + 3 < std::ssize(input)) && (j + 3 < std::ssize(input.front())))
        {
            count += (std::views::iota(0, 4)
                | std::views::transform([&](const auto& offset) {return input[i + offset][j + offset]; })
                | std::ranges::to<std::string>()).contains("XMAS");
        }

        // down left
        if ((i + 3 < std::ssize(input)) && (j - 3 >= 0))
        {
            count += (std::views::iota(0, 4)
                | std::views::transform([&](const auto& offset) {return input[i + offset][j - offset]; })
                | std::ranges::to<std::string>()).contains("XMAS");
        }

        return count;
    }
}

int count_xmas(const std::vector<std::string>& input)
{
    const auto reversed_input = input
        | std::views::reverse
        | std::views::transform([](const auto& str) { return str | std::views::reverse | std::ranges::to<std::string>(); })
        | std::ranges::to<std::vector>();

    return std::ranges::fold_left(std::views::cartesian_product(
        std::views::iota(ptrdiff_t{ 0 }, std::ssize(input)),
        std::views::iota(ptrdiff_t{ 0 }, std::ssize(input.front())))
        | std::views::transform([&](const auto& coordinates)
            {
                const auto [i, j] = coordinates;
                auto count = 0;
                if (input[i][j] == 'X') count += search_around_x(i, j, input);
                if (reversed_input[i][j] == 'X') count += search_around_x(i, j, reversed_input);

                return count;
            }), 0, std::plus{});
}