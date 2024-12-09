#include "day4_part1.h"

#include <iostream>
#include <ranges>

auto search_around_x(const ptrdiff_t i0, const ptrdiff_t j0, const std::vector<std::string>& input)
{
    auto count = 0;

    // down
    count += (input
        | std::views::drop(i0)
        | std::views::transform([&](const auto& row) {return row[j0]; })
        | std::views::take(4)
        | std::ranges::to<std::string>()).contains("XMAS");

    // right
    count += (input[i0]
        | std::views::drop(j0)
        | std::views::take(4)
        | std::ranges::to<std::string>()).contains("XMAS");

    // down right
    if ((i0 + 3 < std::ssize(input)) && (j0 + 3 < std::ssize(input.front())))
    {
        count += (std::views::iota(0, 4)
            | std::views::transform([&](const auto& i) {return input[i0 + i][j0 + i]; })
            | std::ranges::to<std::string>()).contains("XMAS");
    }

    // down left
    if ((i0 + 3 < std::ssize(input)) && (j0 - 3 >= 0))
    {
        count += (std::views::iota(0, 4)
            | std::views::transform([&](const auto& i) {return input[i0 + i][j0 - i]; })
            | std::ranges::to<std::string>()).contains("XMAS");
    }

    return count;
}

int count_xmas(const std::vector<std::string>& input)
{
    const auto reversed_input = input
        | std::views::reverse
        | std::views::transform([](const auto& str) { return str | std::views::reverse | std::ranges::to<std::string>(); })
        | std::ranges::to<std::vector>();

    int count = 0;
    for (ptrdiff_t i = 0; i < std::ssize(input); ++i)
    {
        for (ptrdiff_t j = 0; j < std::ssize(input.front()); ++j)
        {
            if (input[i][j] == 'X') count += search_around_x(i, j, input);
            if (reversed_input[i][j] == 'X') count += search_around_x(i, j, reversed_input);
        }
    }

    return count;
}