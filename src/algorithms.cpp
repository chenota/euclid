#include "algorithms.hpp"

#define DELIM (latex ? " & " : "\t")
#define END (latex ? "\\\\\n" : "\n")

int euclid_basic(int a, int b, int depth, bool verbose, bool latex) {
    // Verbose print
    if(verbose) {
        // Print table header
        if(depth == 0) std::cout << 'i' << DELIM << 'a' << DELIM << 'b' << std::endl;
        // Print table body
        std::cout << depth << DELIM << a << DELIM << b << std::endl;
    }
    // Return a if b is zero
    if(b == 0) return a;
    // Recurse
    return euclid_basic(b, a % b, depth + 1, verbose, latex);
}

int euclid_extended(int rp, int rpp, int *xp, int *xpp, int *yp, int *ypp, int depth, bool verbose, bool latex) {
    if(depth == 0) {
        // Print table header and first two rows
        if(verbose) {
            std::cout << 'i' << DELIM << 'r' << DELIM << 'q' << DELIM << 'x' << DELIM << 'y' << END;
            std::cout << "-1" << DELIM << rpp << DELIM << DELIM << '1' << DELIM << '0' << END;
            std::cout << "0" << DELIM << rp << DELIM << DELIM << '0' << DELIM << '1' << END;
        }
        // Fill in values for x and y
        *xp = 0;
        *yp = 1;
        *xpp = 1;
        *ypp = 0;
        // Move on to depth = 1
        return euclid_extended(rp, rpp, xp, xpp, yp, ypp, depth + 1, verbose, latex);
    } else {
        // Calculate remainder
        int r = rpp % rp;
        // Calculate quotient
        int q = rpp / rp;
        // Calculate x and y
        int x = *xpp - (q * *xp);
        int y = *ypp - (q * *yp);
        // Verbose print
        if(verbose && r == 0) std::cout << depth << DELIM << r << DELIM << q << DELIM << DELIM << END;
        else if(verbose) std::cout << depth << DELIM << r << DELIM << q << DELIM << x << DELIM << y << END;
        // Return previous non-zero value if remainder is zero
        if(r == 0) return rp;
        // Shift x and y values up
        *xpp = *xp;
        *ypp = *yp;
        *xp = x;
        *yp = y;
        // Recurse
        return euclid_extended(r, rp, xp, xpp, yp, ypp, depth + 1, verbose, latex);
    }
}