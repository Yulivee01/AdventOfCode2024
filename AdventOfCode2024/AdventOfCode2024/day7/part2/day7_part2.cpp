#include "day7_part2.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>

namespace
{
    size_t concatenate_integers(const size_t lhs, const int rhs)
    {
        const auto num_digits_rhs = rhs == 0 ? 1 : static_cast<size_t>(std::log10(rhs)) + 1;
        return lhs * static_cast<size_t>(std::pow(10, num_digits_rhs)) + rhs;
    }

    bool is_fold_valid(const calibration& cal, const size_t init_val, const std::function<size_t(size_t, int)>& func)
    {
        return std::ranges::fold_left(cal.numbers, init_val, func) == cal.result;
    }

    bool is_one_operator_valid(const calibration& cal)
    {
        return is_fold_valid(cal, 0, std::plus{})
            || is_fold_valid(cal, 1, std::multiplies{})
            || is_fold_valid(cal, 0, concatenate_integers);
    }

    bool is_operator_combination_valid(
        const std::vector<int>& operators,
        const calibration& cal,
        const size_t init_val,
        const std::function<size_t(size_t, int)>& func1,
        const std::function<size_t(size_t, int)>& func2)
    {
        auto idx = 0;
        const auto cal_result = std::ranges::fold_left(cal.numbers, init_val, [&](const auto sum, const auto val)
            {
                return operators[idx++] == 1 ? func1(sum, val) : func2(sum, val);
            });

        return cal_result == cal.result;
    }

    bool is_calibration_valid_two_operators(const calibration& cal)
    {
        auto operator_combinations = std::vector(cal.numbers.size() - 1, 1);
        for (size_t i = 0; i < cal.numbers.size() - 2; ++i)
        {
            operator_combinations[i] = 0;
            do
            {
                // add initial operator for fold_left
                auto operators = operator_combinations;
                operators.insert(operators.begin(), 1);

                if (is_operator_combination_valid(operators, cal, 0, std::plus{}, std::multiplies{})
                    || is_operator_combination_valid(operators, cal, 0, std::plus{}, concatenate_integers)
                    || is_operator_combination_valid(operators, cal, 1, std::multiplies{}, concatenate_integers))
                    return true;

            } while (std::ranges::next_permutation(operator_combinations).found);
        }

        return false;
    }

    bool is_calibration_valid_three_operators(const calibration& cal)
    {
        auto operator_combinations = std::vector(cal.numbers.size() - 1, 2);
        for (size_t i = 0; i < cal.numbers.size() - 1; ++i)
        {
            operator_combinations[i] = 0;
            auto op_save = operator_combinations;
            for (size_t j = i + 1; j < cal.numbers.size() - 1; ++j)
            {
                operator_combinations[j] = 1;
                do
                {
                    // add initial operator for fold_left
                    auto operators = operator_combinations;
                    operators.insert(operators.begin(), 0);

                    auto idx = 0;
                    const auto cal_result = std::ranges::fold_left(cal.numbers, size_t{ 0 }, [&](const auto sum, const auto val)
                        {
                            switch (operators[idx++])
                            {
                            case 0: return sum + val;
                            case 1: return sum * val;
                            case 2: return concatenate_integers(sum, val);
                            default: return sum;
                            }
                        });

                    if (cal_result == cal.result) return true;
                } while (std::ranges::next_permutation(operator_combinations).found);
            }

            operator_combinations = op_save;
        }

        return false;
    }

    bool is_calibration_valid(const calibration& cal)
    {
        return is_fold_valid(cal, 1, std::multiplies{})
            || is_fold_valid(cal, 0, std::plus{})
            || is_fold_valid(cal, 0, concatenate_integers)
            || is_calibration_valid_two_operators(cal)
            || is_calibration_valid_three_operators(cal);
    }
}


size_t find_valid_calibrations2(const std::vector<calibration>& calibrations)
{
    return std::ranges::fold_left(
        calibrations
        | std::views::filter(&is_calibration_valid)
        | std::views::transform(&calibration::result),
        size_t{ 0 },
        std::plus{});
}