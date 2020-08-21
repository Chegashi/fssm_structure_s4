#include <stdio.h>
//  1- le passage par adresse ca veut dire que on accede a la valeur stocker par la variable non pas par le nom ms par l'adresse de celci
//  2- a = 8, b = 2
void faitQuoi(int *x,int *y, int d)
{
    *x = *x + d;
    *y = *y + d;
}
void    minMax(double *x, double *y)
{
    double min ,max ;
    if(*y > *x)
        {
            max = *y;
            min = *x;
         }
    else
    {
        max = *x;
        min = *y;
    }
    *x = min;
    *y = max; 
}

void tree3nbr(double *x,double *y,double *z)
{
    minMax(x,y);
    minMax(y,z);
    minMax(x,y);

}

int main(int argc, char const *argv[])
{
    double a = 1;
    double b = 3;
    double c = 2;
    tree3nbr(&a,&b,&c);
    printf("a = %lf, b = %lf, c= %lf",a,b,c);
    return 0;
}
