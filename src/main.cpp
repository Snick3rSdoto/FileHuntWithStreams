#include "searchFileLib.h"

int main(int argc, char* argv[]) {
    std::string rootDirectory = "/";
    std::string fileNameToFind = argv[1];

    searchFileThreaded(rootDirectory, fileNameToFind);

    return 0;
}


