#include "or_gate.h"

void or_gate(ap_uint<1> a, ap_uint<1> b, ap_uint<1> &c) {
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE ap_none port=a
    #pragma HLS INTERFACE ap_none port=b
    #pragma HLS INTERFACE ap_none port=c
    
    const data_t w1 = 1.0f;
    const data_t w2 = 1.0f;
    const data_t bias = -0.5f;

    data_t z = (a * w1) + (b * w2) + bias;
    
    if (z >= 0.0) {
        c = 1;
    }else {
        c = 0;
    }
}
