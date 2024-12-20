#include "day6_part2.h"
#include "../read_input_day6.h"

#include <gtest/gtest.h>

TEST(day_6_part2, test_with_aoc_example)
{
    auto map = std::vector<std::string>{
    {"....#....."},
    {".........#"},
    {".........."},
    {"..#......."},
    {".......#.."},
    {".........."},
    {".#..^....."},
    {"........#."},
    {"#........."},
    {"......#..."} };

    EXPECT_EQ(6, count_loops(map));
}

TEST(day_6_part2, test_with_full_input)
{
    auto map = read_input_day6("day6/input_day6.txt");
    EXPECT_EQ(1663, count_loops(map));
}