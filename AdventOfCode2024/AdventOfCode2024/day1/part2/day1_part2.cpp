#include "day1_part2.h"

#include <algorithm>
#include <functional>
#include <ranges>

int calc_similarity_score(const std::span<const int> input1, const std::span<const int> input2)
{
    const auto calc_score = [&](const auto num) {return num * static_cast<int>(std::ranges::count(input2, num)); };
    return std::ranges::fold_left(input1 | std::views::transform(calc_score), 0, std::plus{});
}
