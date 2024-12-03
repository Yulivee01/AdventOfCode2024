#include "../day3_part1.h"

#include <algorithm>
#include <functional>
#include <ranges>
#include <regex>

int perform_valid_multiplications(const std::string& input)
{
    const auto find_valid_multiplication = std::regex(R"(mul\(\d+,\d+\))");
    const auto find_number = std::regex(R"(\d+)");

    const auto regex_range = std::ranges::subrange(std::sregex_iterator(input.begin(), input.end(), find_valid_multiplication), std::sregex_iterator());
    return std::ranges::fold_left(regex_range | std::views::transform([&](const auto& match)
        {
            const auto& mul_str = match.str();
            const auto match_range = std::ranges::subrange(std::sregex_iterator(mul_str.begin(), mul_str.end(), find_number), std::sregex_iterator());
            return std::ranges::fold_left(match_range | std::views::transform([](const auto& num) {return std::stoi(num.str()); }), 1, std::multiplies{});
        }), 0, std::plus{});
}