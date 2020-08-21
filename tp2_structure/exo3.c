#include <stdio.h>
#include <stdlib.h>

typedef struct dis
{
    int m;
    int cm;
}dis;
int main(int argc, char const *argv[])
{
    dis d1,d2,d3;

    printf("\npremier distance");
    printf("\nmetres="); scanf("%d",&d1.m);
    printf("\ncentimetres=");scanf("%d",&d1.cm);
    printf("\ndeuxieme distance");
    printf("\nmetres=");scanf("%d",&d2.m);
    printf("\ncentimetres=");scanf("%d",&d2.cm);
    d3.m = d1.m + d2.m + (d1.cm + d2.cm)/100;
    d3.cm =  (d1.cm + d2.cm)%100;
    printf("somme de deux distance : %d metres , %d centimetres",d3.m, d3.cm);
    return 0;
}
