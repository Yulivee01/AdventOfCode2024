#include "day1_part2.h"
#include "../read_input_day1.h"

#include <gtest/gtest.h>

#include <vector>

TEST(day1_part2, test_with_aoc_example)
{
    const auto input1 = std::vector{ 3, 4, 2, 1, 3, 3 };
    const auto input2 = std::vector{ 4, 3, 5, 3, 9, 3 };
    EXPECT_EQ(31, calc_similarity_score(input1, input2));
}

TEST(day1_part2, test_with_full_input)
{
    const auto [input1, input2] = read_input("day1/input_day1.txt");
    EXPECT_EQ(20520794, calc_similarity_score(input1, input2));
}
