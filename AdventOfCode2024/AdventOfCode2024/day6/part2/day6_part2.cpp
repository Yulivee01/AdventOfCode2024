#include "day6_part2.h"
#include "../utilities.h"

#include <algorithm>
#include <optional>

int count_loops(std::vector<std::string>& map)
{
    const auto start_position = find_start(map);

    auto loops = 0;
    // set an obstacle at every position of the map and check if we are in a loop
    for (ptrdiff_t i = 0; i < std::ssize(map); ++i)
    {
        for (ptrdiff_t j = 0; j < std::ssize(map.front()); ++j)
        {
            // set start position and direction
            auto position = start_position;
            auto dir = direction::up;

            // initialize position counter
            auto count_pos = std::vector<std::vector<int>>(map.size());
            for (auto& s : count_pos) s.resize(map.front().size());

            // skip if i and y are at start position -> no obstacle can be placed at start position
            if (start_position.x == i && start_position.y == j) continue;

            // save original value and set obstacle
            auto org_val = map[i][j];
            map[i][j] = '#';

            // test for loops with obstacle at i/j
            while (position.x > -1 && position.x < std::ssize(map) && position.y > -1 && position.y < std::ssize(map.front()))
            {
                // hit obstacle
                if (map[position.x][position.y] == '#')
                {
                    // we are directly on the obstacle so we have to move back a step where we came from
                    correct_position(position, dir);

                    // rotate 90 degrees to the right
                    rotate(dir);
                }

                // test if we are in a loop or going back and forth
                if (count_pos[position.x][position.y] > 2)
                {
                    ++loops;
                    break;
                }

                // update counter
                count_pos[position.x][position.y]++;

                // move forward
                move(position, dir);
            }

            // reset map
            map[i][j] = org_val;
        }
    }

    return loops;
}