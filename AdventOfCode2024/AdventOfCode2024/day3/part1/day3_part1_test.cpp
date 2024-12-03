#include "../day3_part1.h"
#include "../read_input_day3.h"

#include <gtest/gtest.h>

TEST(day_3_part1, test_with_aoc_example)
{
    const auto input = R"(xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5)))";
    EXPECT_EQ(161, perform_valid_multiplications(input));
}

TEST(day_3_part1, test_with_full_input)
{
    const auto input = read_input_day3("day3/input_day3.txt");
    EXPECT_EQ(180233229, perform_valid_multiplications(input));
}