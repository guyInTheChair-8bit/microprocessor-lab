#ifndef NAND_GATE_H
#define NAND_GATE_H

#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_fixed<8,4> data_t;

void nand_train(
    ap_uint<8> &w1_mag,   ap_uint<1> &w1_sign,
    ap_uint<8> &w2_mag,   ap_uint<1> &w2_sign,
    ap_uint<8> &bias_mag, ap_uint<1> &bias_sign
);

#endif
