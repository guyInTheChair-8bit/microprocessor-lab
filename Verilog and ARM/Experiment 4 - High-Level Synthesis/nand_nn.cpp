#include "nand_gate.h"

void nand_train(
    ap_uint<8> &w1_mag,   ap_uint<1> &w1_sign,
    ap_uint<8> &w2_mag,   ap_uint<1> &w2_sign,
    ap_uint<8> &bias_mag, ap_uint<1> &bias_sign
) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=w1_mag
#pragma HLS INTERFACE ap_none port=w1_sign
#pragma HLS INTERFACE ap_none port=w2_mag
#pragma HLS INTERFACE ap_none port=w2_sign
#pragma HLS INTERFACE ap_none port=bias_mag
#pragma HLS INTERFACE ap_none port=bias_sign

    float w1_val   =  0.5f;
    float w2_val   = -0.3f;
    float bias_val =  0.2f;

    ap_uint<1> a[4] = {0, 0, 1, 1};
    ap_uint<1> b[4] = {0, 1, 0, 1};
    ap_uint<1> c[4] = {1, 1, 1, 0};

    const int   EPOCHS = 20;
    const float eta    = 0.1f;

    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        int errors = 0;
        for (int i = 0; i < 4; i++) {
            float z = w1_val * (float)a[i]
                    + w2_val * (float)b[i]
                    + bias_val;
            int y      = (z >= 0.0f) ? 1 : 0;
            int target = (int)c[i];
            int err    = target - y;

            if (err != 0) {
                w1_val   += eta * err * (float)a[i];
                w2_val   += eta * err * (float)b[i];
                bias_val += eta * err;
                errors++;
            }
        }
        if (errors == 0) break;
    }

    float w1_abs   = (w1_val   < 0.0f) ? -w1_val   : w1_val;
    float w2_abs   = (w2_val   < 0.0f) ? -w2_val   : w2_val;
    float bias_abs = (bias_val < 0.0f) ? -bias_val : bias_val;

    w1_mag    = (ap_uint<8>)(w1_abs   * 10.0f);
    w1_sign   = (w1_val   < 0.0f) ? 1 : 0;

    w2_mag    = (ap_uint<8>)(w2_abs   * 10.0f);
    w2_sign   = (w2_val   < 0.0f) ? 1 : 0;

    bias_mag  = (ap_uint<8>)(bias_abs * 10.0f);
    bias_sign = (bias_val < 0.0f) ? 1 : 0;
}
