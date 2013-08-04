/*
 * 即希尔排序,是针对直接插入排序算法的改进，该方法又称缩小增量排序.
 * shellsort: sort v[0]...v[n-1] into increasing order.
 */
#include <stdio.h>

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
	for (i = gap; i < n; i++)
	    for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
	    {
		temp = v[j];
		v[j] = v[j+gap];
		v[j+gap] = temp;
	    }
    
}

int main() {
    int i, a[10] = {3, 2, 1, 7, 5, 9, 10, 11, 19, 20};
    shellsort(a, 10);

    for (i = 0; i < 10; i++)
	printf("%s%d", (i==0?"":" "), a[i]);
    
    return 0;
}
