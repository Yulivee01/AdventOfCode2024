#include "day6_part1.h"
#include "../utilities.h"

#include <algorithm>
#include <ranges>

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