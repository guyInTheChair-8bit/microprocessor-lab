#include <iostream>
#include <iomanip>
#include "nand_gate.h"

int main() {
    ap_uint<8> w1_mag, w2_mag, bias_mag;
    ap_uint<1> w1_sign, w2_sign, bias_sign;

    nand_train(w1_mag, w1_sign, w2_mag, w2_sign, bias_mag, bias_sign);

    float w1   = (w1_sign   ? -1.0f : 1.0f) * (float)w1_mag   / 10.0f;
    float w2   = (w2_sign   ? -1.0f : 1.0f) * (float)w2_mag   / 10.0f;
    float bias = (bias_sign ? -1.0f : 1.0f) * (float)bias_mag / 10.0f;

    std::cout << "============ Trained Perceptron for 2-input NAND ============\n";
    std::cout << "Final weights and bias (from LEDs):\n";
    std::cout << "  w1   = " << w1   << "   (mag=" << w1_mag
              << ", sign=" << w1_sign << ")\n";
    std::cout << "  w2   = " << w2   << "   (mag=" << w2_mag
              << ", sign=" << w2_sign << ")\n";
    std::cout << "  bias = " << bias << "   (mag=" << bias_mag
              << ", sign=" << bias_sign << ")\n\n";

    std::cout << "Verification of 2-input NAND:\n";
    std::cout << "  a  b | z        | c  | expected | status\n";
    std::cout << "  -----+----------+----+----------+-------\n";

    int status = 0;
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            float z = w1 * (float)a + w2 * (float)b + bias;
            int   c = (z >= 0.0f) ? 1 : 0;
            int expected = (a & b) ? 0 : 1;

            bool ok = (c == expected);
            if (!ok) status = 1;

            std::cout << "  " << a << "  " << b << " | "
                      << std::setw(8) << z << " | "
                      << c << "  | " << expected
                      << "        | " << (ok ? "OK" : "FAIL") << "\n";
        }
    }

    std::cout << "\n" << (status ? "FAILED" : "PASSED") << std::endl;
    return 0;
}
