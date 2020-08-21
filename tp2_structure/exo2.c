#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct complex
{
    int x;
    int y;
}complex;

complex    additionCompl(complex a,complex b)
{
    complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}
complex    multipCompl(complex a,complex b)
{
    complex c;
    c.x = a.x * b.x - a.y * b.y;
    c.y = a.x * b.y + b.x * a.y;
    return c;
}
double    modulleCompl(complex a)
{
    return (sqrt(a.x*a.x + a.y*a.y));
}
void    aficherCompl(complex a,complex b)
{
    printf("\n %d + i%d\n",a.x,a.y);
}
complex convert(int r,int teta)
{
    complex a;
    a.x = r * cos(teta);
    a.y = r * sin(teta);
    return(a);
}

int main(int argc, char const *argv[])
{
    printf("s");

    return 0;
}