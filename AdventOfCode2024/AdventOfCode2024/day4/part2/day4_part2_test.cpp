#include "day4_part2.h"
#include "../read_input_day4.h"

#include <gtest/gtest.h>

TEST(day_4_part2, test_with_aoc_example)
{
    const auto input = std::vector<std::string>{
    "MMMSXXMASM",
    "MSAMXMSMSA",
    "AMXSXMAAMM",
    "MSAMASMSMX",
    "XMASAMXAMM",
    "XXAMMXXAMA",
    "SMSMSASXSS",
    "SAXAMASAAA",
    "MAMMMXMMMM",
    "MXMXAXMASX" };

    EXPECT_EQ(9, count_x_mas(input));
}

TEST(day_4_part2, test_with_full_input)
{
    const auto input = read_input_day4("day4/input_day4.txt");
    EXPECT_EQ(1737, count_x_mas(input));
}