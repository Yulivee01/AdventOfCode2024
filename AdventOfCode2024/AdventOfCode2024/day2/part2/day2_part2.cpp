#include "day2_part2.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <ranges>

namespace
{
    auto is_report_valid(const std::span<const int> levels)
    {
        constexpr auto is_negative = [](const auto val) { return val < 0; };
        constexpr auto is_positive = [](const auto val) { return val > 0; };
        constexpr auto are_diffs_within_range = [](const auto val) { return std::ranges::contains(std::array{ 1, 2, 3 }, std::abs(val)); };

        const auto diffs = levels //
            | std::views::pairwise_transform(std::minus{}) //
            | std::ranges::to<std::vector>();

        return ((std::ranges::all_of(diffs, is_negative) || std::ranges::all_of(diffs, is_positive))
            && std::ranges::all_of(diffs, are_diffs_within_range));
    }

    auto at_least_one_modified_input_is_valid(const std::vector<int>& levels)
    {
        for (int i = 0; i < std::ssize(levels); ++i)
        {
            auto levels_copy = levels;
            levels_copy.erase(levels_copy.begin() + i);

            if (is_report_valid(levels_copy))
            {
                return true;
            }
        }

        return false;
    }
}

std::ptrdiff_t get_number_of_valid_reports_dampened(const std::span<const std::vector<int>> data)
{
    auto num_valid_reports = std::ssize(data);
    for (const auto& levels : data)
    {
        if (!is_report_valid(levels) && !(at_least_one_modified_input_is_valid(levels)))
        {
            --num_valid_reports;
        }
    }

    return num_valid_reports;
}