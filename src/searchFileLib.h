#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>
#include <mutex>

void searchFile(const std::filesystem::path& directory, const std::string& fileName);