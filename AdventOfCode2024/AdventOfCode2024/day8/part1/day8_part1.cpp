#include "day8_part1.h"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>

size_t count_antinodes(const std::string& input, const ptrdiff_t row_size)
{
    // find unique symbols aka antennas
    auto unique_symbols = std::set(input.begin(), input.end());
    unique_symbols.erase('.');

    auto antinodes = std::string(input.size(), '.');
    // find antinodes per antenna
    for (const auto symbol : unique_symbols)
    {
        // find all indices of one antenna
        auto indices_symbol = std::vector<ptrdiff_t>();
        indices_symbol.reserve(input.size());
        for (const auto [index, value] : std::views::enumerate(input))
        {
            if (value == symbol)
            {
                indices_symbol.push_back(index);
            }
        }

        for (size_t i = 2; i < indices_symbol.size() + 1; ++i)
        {
            for (const auto subrange : indices_symbol | std::views::slide(i))
            {
                const auto distance = subrange.back() - subrange.front();

                const auto front_idx_in_row = subrange.front() % row_size;
                const auto lower_index = subrange.front() - distance;
                const auto lower_idx_in_row = lower_index % row_size;

                const auto back_idx_in_row = subrange.back() % row_size;
                const auto upper_index = subrange.back() + distance;
                const auto upper_index_in_row = upper_index % row_size;

                if (lower_index > 0)
                {
                    // direction is from upper to lower right
                    if (front_idx_in_row < back_idx_in_row)
                    {
                        if (front_idx_in_row >= lower_idx_in_row) antinodes[lower_index] = '#';
                    }
                    else
                    {
                        if (front_idx_in_row <= lower_idx_in_row) antinodes[lower_index] = '#';
                    }
                }

                if (upper_index < std::ssize(input) - 1)
                {
                    // direction is from upper to lower right
                    if (front_idx_in_row < back_idx_in_row)
                    {
                        if (back_idx_in_row <= upper_index_in_row) antinodes[upper_index] = '#';
                    }
                    else
                    {
                        if (back_idx_in_row >= upper_index_in_row) antinodes[upper_index] = '#';
                    }
                }
            }
        }
    }

    //for (int idx = 0; const auto i : antinodes)
    //{
    //    std::cout << i << " ";
    //    idx++;
    //    if (idx % row_size == 0) std::cout << std::endl;
    //}

    return std::ranges::count(antinodes, '#');
}
