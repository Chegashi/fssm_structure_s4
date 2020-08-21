#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int avg(int *tab, int n)
{
    int s = 0;
    for (size_t i = 0; i < n; i++)
        s += tab[i];
    return (s);
    
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,9};
    int b[] = {1,2,3,4,0,6,7,8,9,9};
    printf("\n %d", avg(a,1));
    printf("\n %d", avg(b,1));
    memcmp(a,b,10) != 0 ? printf("\nles deux tableaux sont identique") : printf("\nles deux tableaux n'ont pas identique");
    return 0;
}