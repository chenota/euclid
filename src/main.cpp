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
    // Run specified algorithm
    int result, x, xp, y, yp;
    if(algorithm == BASIC) {
        result = euclid_basic(a, b, 0, mode == VERBOSE);
    } else {
        result = euclid_extended(b, a, &x, &xp, &y, &yp, 0, mode == VERBOSE);
    }
    // Print result
    if(mode == VERBOSE) {
        std::cout << std::endl << "GCD(" << a << ", " << b << ") = " << result << std::endl;
        if(algorithm == EXTENDED) {
            std::cout << std::endl << "Multiplicative Inverse of " << b << " (mod " << a << ") = ";
            if(result == 1) std::cout << (y < 0 ? y + a : y);
            else std::cout << "undefined";
            std::cout << std::endl;
        }
    } else {
        std::cout << result << std::endl;
    }
    // Exit success
    return 0;
}