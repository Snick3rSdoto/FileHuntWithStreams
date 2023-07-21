#include "searchFileLib.h"

int main() {
    std::string rootDirectory = "/";
    std::string fileNameToFind = "aboba222";

    searchFileThreaded(rootDirectory, fileNameToFind);

    return 0;
}


