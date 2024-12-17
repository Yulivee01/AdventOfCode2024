#include "day6_part1.h"

#include <algorithm>
#include <ranges>

namespace
{
    enum class direction
    {
        up,
        down,
        left,
        right
    };

    struct position
    {
        ptrdiff_t x{};
        ptrdiff_t y{};
    };

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
}

ptrdiff_t count_locations(std::vector<std::string>& map)
{
    auto position = find_start(map);
    auto direction = direction::up;
    while (position.x > -1 && position.x < std::ssize(map) && position.y > -1 && position.y < std::ssize(map.front()))
    {
        if (map[position.x][position.y] == '#')
        {
            correct_position(position, direction);
            rotate(direction);
        }

        map[position.x][position.y] = 'X';
        move(position, direction);
    }

    return std::ranges::count(map | std::views::join, 'X');
}