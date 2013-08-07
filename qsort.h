//qsort 的另类写法,写起来很简单

#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void _qsort(int v[], int left, int right) {
    int i, last;

    if (left >= right)
        return ;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i<=right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last-1);
    _qsort(v, last+1, right);
}

int main(){
    int a[] = {4, 32, 1, 5}, i;

    _qsort(a, 0, 3);

    for (i=0; i<=3; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    return 0;
}
