#include "day5_part2.h"

#include <algorithm>
#include <ranges>

int make_updates_valid(const std::vector<std::pair<int, int>>& rules, const std::vector<std::vector<int>>& updates)
{
    const auto comp = [&](const auto left, const auto right)
        {
            return std::ranges::contains(rules, std::pair{ left, right });
        };

    return std::ranges::fold_left(updates
        | std::views::filter([&](const auto& update)
            {
                return !std::ranges::is_sorted(update, comp);
            })
        | std::views::transform([&](auto update)
            {
                std::ranges::sort(update, comp);
                return update[update.size() / 2];
            }),
        0, std::plus{});
}