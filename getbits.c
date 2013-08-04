/*
 * get n bits from positon p
 * 注意: 返回的是右对其的,即从右向左从0开始编号
 * 例如编号 8 7 6 5 4 3 2 1 0
 * getbits(x, 4, 3);
 * 会返回编号 4 3 2 1
 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main() {
    int i, a[100], j;

    unsigned n = getbits(0xA, 3, 2);
    printf("%u\n", n);
    
    return 0;
}
