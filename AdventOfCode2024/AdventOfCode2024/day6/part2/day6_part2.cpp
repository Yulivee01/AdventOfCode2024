#include "day6_part2.h"
#include "../utilities.h"

#include <algorithm>
#include <iostream>
#include <optional>
#include <ranges>

namespace
{
    direction opposite(const direction& dir)
    {
        switch (dir)
        {
        case direction::up:
            return direction::down;
        case direction::down:
            return direction::up;
        case direction::left:
            return direction::right;
        case direction::right:
            return direction::left;
        default:
            return direction::up;
        }
    }
}

int count_loops(std::vector<std::string>& map)
{
    const auto start_position = find_start(map);

    auto loops = 0;
    for (ptrdiff_t i = 0; i < std::ssize(map); ++i)
    {
        for (ptrdiff_t j = 0; j < std::ssize(map.front()); ++j)
        {
            auto position = start_position;
            auto dir = direction::up;

            auto state = std::vector<std::vector<std::pair<std::optional<direction>, int>>>(map.size());
            for (auto& s : state) s.resize(map.front().size());

            if (start_position.x == i && start_position.y == j) break;

            auto org_val = map[i][j];
            map[i][j] = '#';

            //std::cout << " i " << i << " j " << j << std::endl;
            while (position.x > -1 && position.x < std::ssize(map) && position.y > -1 && position.y < std::ssize(map.front()))
            {
                //if (i == 4 && j == 8)
                //{
                //    std::cout
                //        << "x " << position.x
                //        << " y " << position.y
                //        << " map[position.x][position.y] " << map[position.x][position.y]
                //        << " state[position.x][position.y] " << (state[position.x][position.y].has_value() ? static_cast<int>(*state[position.x][position.y]) : -1)
                //        << std::endl;
                //}

                if (map[position.x][position.y] == '#')
                {
                    correct_position(position, dir);
                    rotate(dir);
                }

                if (state[position.x][position.y].first.has_value()
                    && (state[position.x][position.y].first == dir
                        || (state[position.x][position.y].first == opposite(dir) && state[position.x][position.y].second > 2)))
                {
                    ++loops;
                    break;
                }

                state[position.x][position.y].first = dir;
                state[position.x][position.y].second++;
                move(position, dir);

                //if (std::ranges::all_of(state | std::views::join, [](const auto opt) {return opt.has_value(); })) break;
            }

            map[i][j] = org_val;
        }
    }

    return loops;
}