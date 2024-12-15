#include "day5_part1.h"
#include "../read_input_day5.h"

#include <gtest/gtest.h>

TEST(day_5_part1, test_with_aoc_example)
{
    const auto rules = std::vector<std::pair<int, int>>{ { 47, 53 },{ 97, 13 },{ 97, 61 },{ 97, 47 },{ 75, 29 },
                                                         { 61, 13 },{ 75, 53 },{ 29, 13 },{ 97, 29 },{ 53, 29 },
                                                         { 61, 53 },{ 97, 53 },{ 61, 29 },{ 47, 13 },{ 75, 47 },
                                                         { 97, 75 },{ 47, 61 },{ 75, 61 },{ 47, 29 },{ 75, 13 },{ 53, 13 } };

    const auto updates = std::vector<std::vector<int>>{ { 75, 47, 61, 53, 29 },
                                                        { 97, 61, 53, 29, 13 },
                                                        { 75, 29, 13 },
                                                        { 75, 97, 47, 61, 53 },
                                                        { 61, 13, 29 },
                                                        { 97, 13, 75, 29, 47 } };

    EXPECT_EQ(143, valid_updates(rules, updates));
}

TEST(day_5_part1, test_with_full_input)
{
    const auto rules = read_rules("day5/input_day5_1.txt");
    const auto updates = read_updates("day5/input_day5_2.txt");
    EXPECT_EQ(7198, valid_updates(rules, updates));
}