/*Ecrire un programme qui permet de gérer une file par une liste chainée. Il doit contenir
les fonctions suivantes :
- creer : pour la création
- testVide : si la file est vide ou non
- testPlein : si la file est pleine ou non
- trier : pour trier les éléments d’une file par ordre croissant
- enfiler : pour ajouter des éléments
- defiler : pour enlever des éléments
- afficher : pour afficher la file
- main() : pour tester.*/

#include <stdlib.h>
#include <stdio.h>

typedef struct element
{
    int data;
    struct element *precedent;
}element;

typedef struct file
{
   struct element *last;
}file;

file    *creer()
{
    file *f = (file *) malloc(sizeof(creer));
    element *e = (element *)malloc(sizeof(element));
    f->last = NULL;
    return(f);
}

void enfiler(file *f, int nb)
{
    element *e = (element *)malloc(sizeof(element));
    e->data = nb;
    e->precedent = f->last;
    f->last = e;
}

void    afficher(file *f)
{
    element *actuel = f->last;
    printf("\n");
    while (actuel)
    {
        printf("%d<-", actuel->data);
        actuel = actuel->precedent;
    }
    
}

int testVide(file *f)
{
    return(f->last ? 1 : 0 );
}

int testPlein(file *f)
{
    return(f->last ? 0 : 1 );

}

void    defiler(file *f, element *e)
{
    element *e_2;
    
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