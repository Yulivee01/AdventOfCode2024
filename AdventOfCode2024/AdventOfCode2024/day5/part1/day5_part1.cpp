#include "day5_part1.h"

#include <algorithm>
#include <ranges>

int valid_updates(const std::vector<std::pair<int, int>>& rules, const std::vector<std::vector<int>>& updates)
{
    return std::ranges::fold_left(updates
        | std::views::filter([&](const auto& update)
            {
                return std::ranges::is_sorted(update, [&](const auto left, const auto right)
                    {
                        return std::ranges::contains(rules, std::pair{ left, right });
                    });
            })
        | std::views::transform([&](const auto& update) {return update[update.size() / 2]; }),
        0, std::plus{});
}