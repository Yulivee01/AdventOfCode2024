#include "../day3_part1.h"
#include "day3_part2.h"

#include <iostream>

int perform_valid_multiplications_trimmed(const std::string& input)
{
    auto trimmed_input = input;

    size_t do_not_pos = 0;
    while (do_not_pos != std::string::npos)
    {
        do_not_pos = trimmed_input.find("don't", 0);
        const auto next_do_pos = trimmed_input.find("do", do_not_pos + 1);

        if (do_not_pos == std::string::npos) break;

        if (next_do_pos == std::string::npos)
        {
            trimmed_input.erase(do_not_pos, trimmed_input.size() - do_not_pos);
            break;
        }

        trimmed_input.erase(do_not_pos, next_do_pos - do_not_pos);
    }

    return perform_valid_multiplications(trimmed_input);
}
