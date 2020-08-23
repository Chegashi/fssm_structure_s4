/*
**  Soit P une pile contenant des entiers de 1 jusqu’à 50. On veut séparer ces entiers en entiers pairs
**  et impairs. Les pairs seront stockés dans une pile Q et les impairs dans une pile S.
**  Créer ces piles en utilisant les deux approches : tableaux et listes chainées. Utiliser toutes les
**  fonctions possibles et tester dans le main ().
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct element
{
    int data;
    struct element *next;
}element;

typedef struct pile
{
   struct element *first;
}pile;

pile    *define_pile()
{
    pile *P = (pile *) malloc(sizeof( pile));
    element *e = (element *)malloc(sizeof(element));
    P->first = NULL;
    return(P);
}

void empiler(pile *P, int nb)
{
    element *e = (element *)malloc(sizeof(element));
    e->data = nb;
    e->next = P->first;
    P->first = e;
}

void    print_pile(pile *P)
{
    element *actuel = P->first;
    printf("\n");
    while (actuel)
    {
        printf("%d->", actuel->data);
        actuel = actuel->next;
    }
    
}
int main(int argc, char const *argv[])
{
    pile *P = define_pile();
    for (size_t i = 1; i <= 50; i++)
        empiler(P, i);    
    print_pile(P);
    pile *Q = define_pile();
    pile *S = define_pile();
    element *e = P->first;
    while (e)
    {
        (e->data %2) ? empiler(Q, e->data) :empiler(S, e->data) ;
        e = e->next;
    }
    print_pile(S);
    print_pile(Q);
    
    return 0;
}