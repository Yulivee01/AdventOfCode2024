#pragma once

#include <filesystem>
#include <utility>
#include <vector>

std::pair<std::vector<int>, std::vector<int>> read_input(const std::filesystem::path& path);
