#include "LPC214x.h"

static void DACInit(void) {
    PINSEL1 &= ~(3u << 18);
    PINSEL1 |= 2u << 18;
    DACR &= ~(1u << 16);
}

static void delay(void) {
    volatile unsigned int i;
    for (i = 0; i < 10000; ++i) {
    }
}

int main(void) {
    static const unsigned int samples[32] = {
        0x0000, 0x0020, 0x0040, 0x0060, 0x0080, 0x00A0, 0x00C0, 0x00E0,
        0x0100, 0x0120, 0x0140, 0x0160, 0x0180, 0x01A0, 0x01C0, 0x01E0,
        0x0200, 0x0220, 0x0240, 0x0260, 0x0280, 0x02A0, 0x02C0, 0x02E0,
        0x0300, 0x0320, 0x0340, 0x0360, 0x0380, 0x03A0, 0x03C0, 0x03E0
    };
    unsigned int i;
    int j;

    DACInit();
    while (1) {
        for (i = 0; i < 32; ++i) {
            DACR = samples[i] << 6;
            delay();
        }
        for (j = 31; j >= 0; --j) {
            DACR = samples[j] << 6;
            delay();
        }
    }
}
