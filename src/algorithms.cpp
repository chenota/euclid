#include "algorithms.hpp"

int euclid_basic(int a, int b, int depth, bool verbose) {
    // Verbose print
    if(verbose) {
        // Print table header
        if(depth == 0) std::cout << "i\ta\tb" << std::endl;
        // Print table body
        std::cout << depth << '\t' << a << '\t' << b << std::endl;
    }
    // Return a if b is zero
    if(b == 0) return a;
    // Recurse
    return euclid_basic(b, a % b, depth + 1, verbose);
}

int euclid_extended(int rp, int rpp, int *xp, int *xpp, int *yp, int *ypp, int depth, bool verbose) {
    if(depth == 0) {
        // Print table header and first two rows
        if(verbose) {
            std::cout << "i\tr\tq\tx\ty" << std::endl;
            std::cout << "-1\t" << rpp << "\t\t1\t0" << std::endl;
            std::cout << "0\t" << rp << "\t\t0\t1" << std::endl;
        }
        // Fill in values for x and y
        *xp = 0;
        *yp = 1;
        *xpp = 1;
        *ypp = 0;
        // Move on to depth = 1
        return euclid_extended(rp, rpp, xp, xpp, yp, ypp, depth + 1, verbose);
    } else {
        // Calculate remainder
        int r = rpp % rp;
        // Calculate quotient
        int q = rpp / rp;
        // Calculate x and y
        int x = *xpp - (q * *xp);
        int y = *ypp - (q * *yp);
        // Verbose print
        if(verbose && r == 0) std::cout << depth << '\t' << r << '\t' << q << "\t\t" << std::endl;
        else if(verbose) std::cout << depth << '\t' << r << '\t' << q << '\t' << x << '\t' << y << std::endl;
        // Return previous non-zero value if remainder is zero
        if(r == 0) return rp;
        // Shift x and y values up
        *xpp = *xp;
        *ypp = *yp;
        *xp = x;
        *yp = y;
        // Recurse
        return euclid_extended(r, rp, xp, xpp, yp, ypp, depth + 1, verbose);
    }
}