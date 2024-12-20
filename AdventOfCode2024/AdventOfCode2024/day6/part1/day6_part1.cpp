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
        // hit obstacle
        if (map[position.x][position.y] == '#')
        {
            // we are directly on the obstacle so we have to move back a step where we came from
            correct_position(position, direction);

            // rotate 90 degrees to the right
            rotate(direction);
        }

        // mark visited position
        map[position.x][position.y] = 'X';

        // move forward
        move(position, direction);
    }

    // count all visited positions
    return std::ranges::count(map | std::views::join, 'X');
}