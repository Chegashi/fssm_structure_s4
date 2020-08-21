#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//gcc exo02.c && ./a.out 1 2
int main(int argc, char const *argv[])
{
    int a,b;
    int *p_a = &a, *p_b = &b;
    if (argc != 3)
        printf("entrer selement deux nombre");
    else
    {
        a = atoi(argv[1]),b = atoi(argv[2]);
        printf("\n l'addition:\t\t %d + %d = %d.", *p_a, *p_b,*p_a + *p_b);
        printf("\n la soustraction:\t %d + %d = %d.", *p_a, *p_b,*p_a - *p_b);
        printf("\n la multiplication:\t %d + %d = %d.", *p_a, *p_b,*p_a * *p_b);
        if (*p_b)
            printf("\n la division:\t\t %d + %d = %d.", *p_a, *p_b,*p_a / *p_b);
    }
    printf("\n");
    return 0;
}
