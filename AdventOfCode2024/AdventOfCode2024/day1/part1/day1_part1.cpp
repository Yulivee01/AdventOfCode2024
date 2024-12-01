#include "day1_part1.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <ranges>
#include <vector>

int total_distance(const std::span<const int> input1, const std::span<const int> input2)
{
    auto sorted_input1 = std::vector(input1.begin(), input1.end());
    std::ranges::sort(sorted_input1);

    auto sorted_input2 = std::vector(input2.begin(), input2.end());
    std::ranges::sort(sorted_input2);

    const auto abs_difference = [](const int a, const int b) { return std::abs(a - b); };
    return std::ranges::fold_left(std::views::zip_transform(abs_difference, sorted_input1, sorted_input2), 0, std::plus{});
}
