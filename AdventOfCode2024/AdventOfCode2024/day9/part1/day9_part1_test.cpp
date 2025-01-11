#include "day9_part1.h"
#include "../read_input_day9.h"

#include <gtest/gtest.h>

TEST(day_9_part1, test_with_aoc_example)
{
    const auto input = std::vector{ 2, 3, 3, 3, 1, 3, 3, 1, 2, 1, 4, 1, 4, 1, 3, 1, 4, 0, 2 };
    EXPECT_EQ(1928, calculate_filesystem_checksum(input));
}

TEST(day_9_part1, test_with_full_input)
{
    const auto input = read_input_day9("day9/input_day9.txt");
    EXPECT_EQ(554328789, calculate_filesystem_checksum(input));
}
