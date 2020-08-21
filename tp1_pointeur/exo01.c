#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int a = 1;
    int b = 2;
    int c = 3;
    int *p1 , *p2;
    void    print(char *s)
    {
        printf("\n%s\t ---->  %i \t %i \t %i \t %p \t %p \t  ",s,a,b,c,p1,p2);
    }
    printf("1)--------------------");
    printf("\n *p++: va incrementer la valeur du pointeur p");
    printf("\n*(p++) : va incrementer la valeur pointer par le poiteur p ");
    printf("\n (*p)++ equivalent a *p++");
    printf("\n2)--------------------");
    printf("\n\t\t\ta \t b \t c \t p1  \t\t\t p2 \t  ");
                        /*            a       b       c       p1      p2    */  
                        /*            1       2       3        -      -     */  
    p1 = &a;            /*            1       2       3       &a      -     */  print("p1 = &a;");
    p2 = &c;            /*            1       2       3       &a      &c    */  print("*p1 = *p2;");
    *p1 = *p2;          /*            3       2       3       &a      &c    */  print("*p1 = *p2;");
    (*p2)++;            /*            3       2       4       &a      &c    */  print("(*p2)++;");
    p1 = p2;            /*            3       2       4       &c      &c    */  print("p1 = p2;");
    p2 = &b;            /*            3       2       4       &c      &b    */  print("p2 = &b;");
    *p1 -= *p2;         /*            3       2       2       &c      &b    */  print("*p1 -= *p2;");
    *p1 = *p2;          /*            3       2       2       &c      &b    */  print("*p1 = *p2;");
    a = *p2 * *p1;      /*            4       2       2       &c      &b    */  print("a = *p2 * *p1;");     
    p1 = &a;            /*            4       2       2       &a      &b    */  print("p1 = &a;");
    *p2 = *p1/ *p2;     /*            4       2       2       &a      &b    */  print("*p2 = *p1/ *p2;");
    return 0;
}