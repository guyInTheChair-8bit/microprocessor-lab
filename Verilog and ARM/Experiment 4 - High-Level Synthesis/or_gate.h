#ifndef OR_GATE_H
#define OR_GATE_H

#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_fixed<8, 4> data_t;

void or_gate(ap_uint<1> a, ap_uint<1> b, ap_uint<1> &c);

#endif
