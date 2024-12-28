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
        const auto indices_symbol = std::views::enumerate(input)
            | std::views::filter([&](const auto& pair) { return std::get<1>(pair) == symbol; })
            | std::views::transform([](const auto& pair) { return std::get<0>(pair); })
            | std::ranges::to<std::vector>();

        for (const auto i : std::views::iota(size_t{ 2 }, indices_symbol.size() + 1))
        {
            // iterate over all combinations of two antennas
            for (const auto subrange : indices_symbol | std::views::slide(i))
            {
                const auto distance_between_antennas = subrange.back() - subrange.front();

                const auto front_antenna_idx_in_row = subrange.front() % row_size;
                const auto lower_antinode_index = subrange.front() - distance_between_antennas;
                const auto lower_antinode_idx_in_row = lower_antinode_index % row_size;

                const auto back_antinode_idx_in_row = subrange.back() % row_size;
                const auto upper_antinode_index = subrange.back() + distance_between_antennas;
                const auto upper_antinode_idx_in_row = upper_antinode_index % row_size;

                // try to place an antinode in line of two antennas
                // try to place the lower antinode
                // overall index cannot be out of bounds
                if (lower_antinode_index > 0)
                {
                    // direction of the antennas is from upper left to lower right
                    if (front_antenna_idx_in_row < back_antinode_idx_in_row)
                    {
                        // checking if we are in bounds of the row, not going out of the left bound
                        if (front_antenna_idx_in_row >= lower_antinode_idx_in_row) antinodes[lower_antinode_index] = '#';
                    }
                    else
                    {
                        // checking if we are in bounds of the row
                        // when we are going from upper right to lower left, the condition is switched
                        // checking if we are not going out of the right bound
                        if (front_antenna_idx_in_row <= lower_antinode_idx_in_row) antinodes[lower_antinode_index] = '#';
                    }
                }

                // try to place the upper antinode
                if (upper_antinode_index < std::ssize(input) - 1)
                {
                    /// direction of the antennas is from upper left to lower right
                    if (front_antenna_idx_in_row < back_antinode_idx_in_row)
                    {
                        // checking if we are in bounds of the row, not going out of the right bound
                        if (back_antinode_idx_in_row <= upper_antinode_idx_in_row) antinodes[upper_antinode_index] = '#';
                    }
                    else
                    {
                        // checking if we are in bounds of the row
                        // when we are going from upper right to lowe left, the condition is switched
                        // checking if we are not going out of the left bound
                        if (back_antinode_idx_in_row >= upper_antinode_idx_in_row) antinodes[upper_antinode_index] = '#';
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
