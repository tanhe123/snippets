/*
 * bitcount counts the number
 * of 1-bits in its integer argument.
 *
 * in the second method, x &= (x-1) delets
 * the rightmost 1-bit in x.
 */

#include <stdio.h>
/*一种方法
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
	if (x & 01)
	    b++;
    return b;
}
*/    

 //另一种高效的方法
int bitcount(unsigned x)
{
    int b;

    for(b = 0; x != 0; x &= (x-1))
	b++;
    return b;
}

int main() {
    int res;

    res = bitcount(10);
    printf("%d\n", res);
    
    return 0;
}
