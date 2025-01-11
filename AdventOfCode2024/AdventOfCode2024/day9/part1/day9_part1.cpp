#include "day9_part1.h"

#include <algorithm>
#include <optional>
#include <ranges>

namespace
{
    auto map_file_blocks(const std::vector<int>& filesystem_map)
    {
        auto num_spaces = 0;
        auto blocks = std::vector<std::optional<int>>();
        for (int file_index = 0; const auto [idx, block_size] : std::views::enumerate(filesystem_map))
        {
            if (idx % 2 == 0)
            {
                blocks.insert(blocks.end(), block_size, file_index++);
            }
            else
            {
                blocks.insert(blocks.end(), block_size, std::nullopt);
                num_spaces += block_size;
            }
        }

        return std::pair{ blocks, num_spaces };
    }

    auto reorder_files(const int num_spaces, std::vector<std::optional<int>>& blocks)
    {
        for (auto last_idx = std::ssize(blocks) - 1; auto & block: blocks)
        {
            if (!block.has_value())
            {
                auto val = blocks[last_idx];
                while (!val.has_value())
                {
                    val = blocks[--last_idx];
                }

                blocks[last_idx] = std::nullopt;
                block = val;
            }

            if (!std::ranges::search_n(blocks | std::views::reverse, num_spaces, std::optional<int>()).empty()) break;
        }

        blocks.resize(blocks.size() - num_spaces);
    }
}

int calculate_filesystem_checksum(const std::vector<int>& filesystem_map)
{
    auto [blocks, num_spaces] = map_file_blocks(filesystem_map);
    reorder_files(num_spaces, blocks);

    int counter = 0;
    return std::ranges::fold_left(blocks | std::views::transform([&](const auto val) { return *val * counter++; }), 0, std::plus{});
}
