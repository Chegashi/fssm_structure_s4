#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct 
{
    int x;
    int y;
}point;
typedef struct 
{
    point o;
    int r;
}cercle;


int distancepoint(point a,point b)
{
    return(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

int egalPoint(point a,point b)
{
    return (distancepoint(a,b) == 0 ? 1 : 0 );
}

int surfcercle(cercle c)
{
    return(PI * c.r);
}

int appartienCercle(cercle c, point p)
{
    return(distancepoint(p, c.o) > c.r ? 0 : 1 );
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}