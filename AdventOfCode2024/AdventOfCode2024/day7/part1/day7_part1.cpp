#include "day7_part1.h"

#include <algorithm>
#include <functional>
#include <ranges>

namespace
{
    bool is_calibration_valid(const calibration& cal)
    {
        if (std::ranges::fold_left(cal.numbers, size_t{ 1 }, std::multiplies{}) == cal.result
            || std::ranges::fold_left(cal.numbers, size_t{ 0 }, std::plus{}) == cal.result) return true;

        auto operator_combinations = std::vector(cal.numbers.size() - 1, 1);
        for (size_t i = 0; i < cal.numbers.size() - 2; ++i)
        {
            operator_combinations[i] = 0;
            do
            {
                // add initial operator for fold_left
                auto operators = operator_combinations;
                operators.insert(operators.begin(), 1);

                auto idx = 0;
                const auto cal_result = std::ranges::fold_left(cal.numbers, size_t{ 0 }, [&](const auto sum, const auto val)
                    {
                        return operators[idx++] == 1 ? (sum + val) : (sum * val);
                    });

                if (cal_result == cal.result) return true;
            } while (std::ranges::next_permutation(operator_combinations).found);
        }

        return false;
    }
}

size_t find_valid_calibrations(const std::vector<calibration>& calibrations)
{
    return std::ranges::fold_left(
        calibrations
        | std::views::filter(&is_calibration_valid)
        | std::views::transform(&calibration::result),
        size_t{ 0 },
        std::plus{});
}