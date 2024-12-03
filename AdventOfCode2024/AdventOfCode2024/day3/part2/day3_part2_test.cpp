#include "day3_part2.h"
#include "../read_input_day3.h"

#include <gtest/gtest.h>

TEST(day_3_part2, test_with_aoc_example)
{
    const auto input = R"(xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5)))";
    EXPECT_EQ(48, perform_valid_multiplications_trimmed(input));
}

TEST(day_3_part2, test_with_full_input)
{
    const auto input = read_input_day3("day3/input_day3.txt");
    EXPECT_EQ(95411583, perform_valid_multiplications_trimmed(input));
}