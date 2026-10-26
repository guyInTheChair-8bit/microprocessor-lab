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
        0x01FF, 0x0263, 0x02C3, 0x031B, 0x0369, 0x03A9, 0x03D8, 0x03F5,
        0x03FF, 0x03F5, 0x03D8, 0x03A9, 0x0369, 0x031B, 0x02C3, 0x0263,
        0x01FF, 0x019B, 0x013B, 0x00E3, 0x0095, 0x0055, 0x0026, 0x0009,
        0x0000, 0x0009, 0x0026, 0x0055, 0x0095, 0x00E3, 0x013B, 0x019B
    };
    unsigned int i;

    DACInit();
    while (1) {
        for (i = 0; i < 32; ++i) {
            DACR = samples[i] << 6;
            delay();
        }
    }
}
