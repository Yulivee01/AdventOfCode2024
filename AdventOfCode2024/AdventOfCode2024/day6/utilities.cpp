#include "utilities.h"

#include <algorithm>
#include <ranges>

position find_start(const std::vector<std::string>& map)
{
    for (const auto [i, row] : std::views::enumerate(map))
    {
        if (const auto start_it = std::ranges::find(row, '^'); start_it != row.end())
        {
            return { .x = i, .y = std::distance(row.begin(), start_it) };
        }
    }

    return {};
}

void move(position& pos, const direction& dir)
{
    switch (dir)
    {
    case direction::up:
        pos.x -= 1;
        break;
    case direction::down:
        pos.x += 1;
        break;
    case direction::left:
        pos.y -= 1;
        break;
    case direction::right:
        pos.y += 1;
    }
}

void rotate(direction& dir)
{
    switch (dir)
    {
    case direction::up:
        dir = direction::right;
        break;
    case direction::right:
        dir = direction::down;
        break;
    case direction::down:
        dir = direction::left;
        break;
    case direction::left:
        dir = direction::up;
    }
}

void correct_position(position& pos, const direction& dir)
{
    switch (dir)
    {
    case direction::up:
        pos.x += 1;
        break;
    case direction::down:
        pos.x -= 1;
        break;
    case direction::left:
        pos.y += 1;
        break;
    case direction::right:
        pos.y -= 1;
    }
}