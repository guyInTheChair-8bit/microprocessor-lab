#include <iostream>
#include "or_gate.h"

int main() {
    ap_uint<1> a, b, c;

    int STATUS = 0;

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            or_gate(a, b, c);
            if (c != (a | b)) {
                STATUS = 1;
            }
            std::cout << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
        }
    }
    if (!STATUS) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
}
