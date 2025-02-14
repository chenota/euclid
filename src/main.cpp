#include <unistd.h>
#include <iostream>
#include <string>
#include "algorithms.hpp"

int main(int argc, char *argv[]) {
    // Argument parsing
    enum {BASIC, EXTENDED} algorithm = BASIC;
    enum {REGULAR, VERBOSE} mode = REGULAR;
    int c;
    while((c = getopt(argc, argv, "ev")) != -1) {
        switch(c) {
            // -e switches mode to extended
            case 'e':
                algorithm = EXTENDED;
                break;
            // -v switches output mode to verbose
            case 'v':
                mode = VERBOSE;
                break;
            // Unknown option error
            default:
                std::cerr << "Unknown option: " << c << std::endl;
                exit(1);
        }
    }
    // A and B inputs to algorithm
    int a, b;
    // Check positional arguments
    if(argc - optind != 2) {
        std::cerr << "Expected positional arguments A and B" << std::endl;
        exit(1);
    }
    // Get A and B
    a = std::atoi(argv[optind]);
    b = std::atoi(argv[optind + 1]);
    // Exit success
    return 0;
}