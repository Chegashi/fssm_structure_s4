#include <stdio.h>
#include <stdlib.h>

void    permute(double *x, double *y)
{
    double tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void    tabEchange(double tab[], double tab2[], int len)
{
    for (int i = 0; i < len; i++)
        permute((tab + i), (tab2 + i));
    
}

int **readMat(int **A, int line, int colonne)
{
    A = (int**)(malloc(sizeof(int*) * line));
    for (int i = 0; i < colonne; i++)
        A[i] = (int*)malloc(sizeof(int)* colonne);
    for (int j = 0; j < line; j++)
        for (int k = 0; k < colonne; k++)
        {
            printf("\n>>>[%d][%d]=",j,k);
            scanf("%d",&A[j][k]);
        }
    return (A);
}
int     **mul(int **A, int n, int m, int **B, int l,int p, int **C)
{
    int i,j,k,z;
    C = (int**)(malloc(sizeof(int*) * n));
    for (i = 0; i < n; i++)
        C[i] = (int*)malloc(sizeof(int)* p);
    for (j = 0; j < n; j++)
        for (k = 0; k < p; k++)
        {
            C[j][k] = 0;
            for (z = 0; z < m; z++)
                C[j][k] += A[j][z] * B[z][k];
        } 
    return (C);
}
void printMath(int **A, int line, int colonne)
{
    for (int i = 0; i < line; i++)
    {
        printf("\n");

        for (int j = 0; j < colonne; j++)
        {   
            printf("%d\t",A[i][j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int **A=NULL,**B=NULL,**C=NULL;
    A = readMat(A, 2,2);
    B = readMat(B,2,2);
    C = mul(A,2,2,B,2,2,C);
    printMath(C,2,2);
    return 0;
}

