#include "../day3_part1.h"

#include <regex>

int perform_valid_multiplications(const std::string& input)
{
    const auto find_valid_multiplication = std::regex(R"(mul\(\d+,\d+\))");
    const auto find_number = std::regex(R"(\d+)");

    auto sum = 0;
    for (auto mul_it = std::sregex_iterator(input.begin(), input.end(), find_valid_multiplication); mul_it != std::sregex_iterator(); ++mul_it)
    {
        const auto& match = mul_it->str();

        auto prod = 1;
        for (auto num_it = std::sregex_iterator(match.begin(), match.end(), find_number); num_it != std::sregex_iterator(); ++num_it)
        {
            prod *= std::stoi(num_it->str());
        }

        sum += prod;
    }

    return sum;
}