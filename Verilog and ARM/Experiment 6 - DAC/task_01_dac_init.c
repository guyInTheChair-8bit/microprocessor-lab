#include "LPC214x.h"

void DACInit(void) {
    PINSEL1 &= ~(3u << 18);
    PINSEL1 |= 2u << 18;
    DACR &= ~(1u << 16);
}
