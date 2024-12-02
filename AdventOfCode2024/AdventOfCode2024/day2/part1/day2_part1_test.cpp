#include "day2_part1.h"
#include "../read_input_day2.h"

#include <gtest/gtest.h>

TEST(day_2_part1, test_with_aoc_example)
{
    const auto input = std::vector<levels>{
        { 7, 6, 4, 2, 1 },
        { 1, 2, 7, 8, 9 },
        { 9, 7, 6, 2, 1 },
        { 1, 3, 2, 4, 5 },
        { 8, 6, 4, 4, 1 },
        { 1, 3, 6, 7, 9 } };

    EXPECT_EQ(2, get_number_of_valid_reports(input));
}