#include "day8_part2.h"
#include "../read_input_day8.h"

#include <gtest/gtest.h>

TEST(day_8_part2, test_with_simple_example)
{
    const auto input = std::string{
        "T........."
        "...T......"
        ".T........"
        ".........."
        ".........."
        ".........."
        ".........."
        ".........."
        ".........."
        ".........." };

    EXPECT_EQ(9, count_antinodes2(input, 10));
}

TEST(day_8_part2, test_with_aoc_example)
{
    const auto input = std::string{
 "............"
    "........0..."
    ".....0......"
    ".......0...."
    "....0......."
    "......A....."
    "............"
    "............"
    "........A..."
    ".........A.."
    "............"
    "............" };

    EXPECT_EQ(34, count_antinodes2(input, 12));
}

TEST(day_8_part2, test_with_full_input)
{
    const auto input = read_input_day8("day8/input_day8.txt");
    EXPECT_EQ(280, count_antinodes2(input.first, input.second));
}