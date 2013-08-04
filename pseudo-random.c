/*
 * a portable impementation of pseudo-random number generator
 * and a function for initializing the seed.
 * 摘自 《C程序设计语言》（英文版）
 */ 

#include <stdio.h>
#include <time.h>

unsigned long int next = 1;

int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
    next = seed;
}

int main() {
    int i;
    
    srand(time(0));
    for(i=0; i<10; i++) {
	printf("%d\n", rand());
    }
    
    return 0;
}
