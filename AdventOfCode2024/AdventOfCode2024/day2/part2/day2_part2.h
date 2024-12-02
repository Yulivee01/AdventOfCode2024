#pragma once

#include <span>
#include <vector>

std::ptrdiff_t get_number_of_valid_reports_dampened(const std::span<const std::vector<int>> data);
