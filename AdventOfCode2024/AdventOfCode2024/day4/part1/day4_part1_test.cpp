#include "day4_part1.h"
#include "../read_input_day4.h"

#include <gtest/gtest.h>

TEST(count_xmas, test_with_aoc_example)
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

    EXPECT_EQ(18, count_xmas(input));
}

TEST(day_4_part1, test_with_full_input)
{
    const auto input = read_input_day4("day4/input_day4.txt");
    EXPECT_EQ(2358, count_xmas(input));
}