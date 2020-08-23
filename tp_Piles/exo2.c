/*
**      Soit une expression arithmétique correctement écrite. On cherche à transformer cette expression
**      en notation polonaise qui consiste à supprimer les parenthèses et à écrire, contrairement à la
**      notation habituelle, l’opérateur puis les deux opérandes.
**      Exemple :
**      (a+b) devient +ab
**      ((a+b)/(c-d)) devient /+ab-cd
**        Les parenthèses de l’expression doivent être complètes, c'est-à-dire :
**      -
**      -
**      L’expression elle-même doit être entre parenthèses
**      Aucune parenthèse ne peut être sous entendue.
**      Ecrire un programme contenant toutes les fonctions possibles en utilisant les piles par liste
**      chainée qui permet de transformer une expression arithmétique en notation polonaise.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char    *polonaise(pile *p, char *str)
{
    char operateurs[] = "+_*/%";
    int p_o;
    int i = 1;
    while (s[i])
    {
        if (s[i] == '(')
        {
            while (s[++i] != ')')
                ;
            if (strchr(operateurs, s[i]))
            {
                
            }
            
            
        }
        
    }
}

int main(int argc, char const *argv[])
{
    pile *P = define_pile();
    char s[] = "";

    
    return 0;
}
