#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>
#include <list>
#include <chrono>
#include <atomic>

void searchFileThreaded(const std::filesystem::path &directory, const std::string &fileName, int maxThreads = 8);
void searchFileSingle(const std::filesystem::path &directory, const std::string &fileName);