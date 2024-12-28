#include "day7_part1.h"
#include "../read_input_day7.h"

#include <gtest/gtest.h>

TEST(day_7_part1, test_with_aoc_example)
{
    const auto calibrations = std::vector<calibration>{
        {.result = 190, .numbers = {10, 19}},
        {.result = 3267, .numbers = {81, 40, 27}},
        {.result = 83, .numbers = {17, 5}},
        {.result = 156, .numbers = {15, 6}},
        {.result = 7290, .numbers = {6, 8, 6, 15}},
        {.result = 161011, .numbers = {16, 10, 13}},
        {.result = 192, .numbers = {17, 8, 14}},
        {.result = 21037, .numbers = {9, 7, 18, 13}},
        {.result = 292, .numbers = {11, 6, 16, 20}}
    };

    EXPECT_EQ(3749, find_valid_calibrations(calibrations));
}

TEST(day_7_part1, test_with_full_input)
{
    const auto calibrations = read_input_day7("day7/input_day7.txt");
    EXPECT_EQ(2299996598890, find_valid_calibrations(calibrations));
}