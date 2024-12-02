#include "day2_part2.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <ranges>

std::ptrdiff_t get_number_of_valid_reports_(const std::span<const std::vector<int>> data)
{
    //constexpr auto is_negative = [](const auto val) { return val < 0; };
    //constexpr auto is_positive = [](const auto val) { return val > 0; };
    //constexpr auto are_diffs_within_range = [](const auto val) { return std::ranges::contains(std::array{ 1, 2, 3 }, std::abs(val)); };

    //auto valid_reports = data //
    //    | std::views::transform(&levels::level_data) //
    //    | std::views::transform([](const auto& levels) { return levels | std::views::pairwise_transform(std::minus{}); }) //
    //    | std::views::filter([&](const auto& diffs) { return std::ranges::all_of(diffs, is_negative) || std::ranges::all_of(diffs, is_positive); }) //
    //    | std::views::filter([&](const auto& diffs) { return std::ranges::all_of(diffs, are_diffs_within_range); });

    //return std::ranges::distance(valid_reports);

    for (const auto& level : data)
    {
        
    }

    return 0;
}