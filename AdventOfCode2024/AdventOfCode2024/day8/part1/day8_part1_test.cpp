#include "day8_part1.h"
#include "../read_input_day8.h"

#include <gtest/gtest.h>

TEST(day_8_part1, test_with_aoc_example)
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

    EXPECT_EQ(14, count_antinodes(input, 12));
}

TEST(day_8_part1, test_with_example_where_indices_are_out_of_bounds)
{
    const auto input = std::string{
        ".........."
        ".........."
        ".........."
        "....a....."
        "........a."
        ".....a...."
        ".........."
        ".........."
        ".........."
        ".........." };
    EXPECT_EQ(4, count_antinodes(input, 10));
}

TEST(day_8_part1, test_with_example_where_indices_are_up_down)
{
    const auto input = std::string{
        ".........."
        ".........."
        ".........."
        "....a....."
        ".........."
        "....a....."
        ".........."
        ".........."
        ".........." };
    EXPECT_EQ(2, count_antinodes(input, 10));
}

TEST(day_8_part1, test_with_example_where_indices_are_left_right)
{
    const auto input = std::string{
        "..........."
        "....a.a...."
        "..........." };
    EXPECT_EQ(2, count_antinodes(input, 11));
}

TEST(day_8_part1, test_with_full_input)
{
    const auto input = read_input_day8("day8/input_day8.txt");
    EXPECT_EQ(280, count_antinodes(input.first, input.second));
}