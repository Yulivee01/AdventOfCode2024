#pragma once

#include <filesystem>
#include <vector>

#include "calibration.h"

std::vector<calibration> read_input_day7(const std::filesystem::path& path);
