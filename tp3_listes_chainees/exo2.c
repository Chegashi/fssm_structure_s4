/*
Une liste doublement chainée suit le même principe qu’une liste simplement chainée sauf que
chaque nœud de la liste possède deucontentelementeurs : un vers le nœud suivant et l’autre vers le
nœud précédent.
Créer des fonctions de création, d’insertion, de modification et d’affichage (parcourt dans les
deucontentsens) d’une liste d’entiers doublement chainée.
*/
/*
Soit une liste simplement chainée d’éléments composés. On suppose ces éléments des elements
d’un liste cartésien. Chaque element est identifié par une ordonnée (y) et une abscisse (x) de type
float.
1- Définir la structure correspondante à ce type composé.
2- On veut gérer cette liste par les fonctions suivantes.
• Creation(), pour créer la liste.
• InsertElement(), pour insérer un élément au début.
• InsertPos(), pour insérer un élément devant une position donnée.
• InsertFin(), pour insérer un élément à la fin de la liste.
• Chercher(), pour chercher un élément donné.
• Suppression(), pour supprimer un élément donné. On ne peut supprimer que
des éléments trouvés par la fonction Chercher().
• Modification(), pour modifier un élément donné. On ne peut supprimer que
des éléments trouvés par la fonction Chercher().
• Afficher(), pour afficher la liste.
3- Dans la fonction main(), vous créez un menu interactif illustrant les choicontentnumérotés
qu’on peut faire. Prenez en considération qu’on ne peut appliquer aucune des
fonctions que si la liste est déjà créée.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int content;
    struct element *next;
    struct element *precedent;
}element;


typedef struct liste
{
    element *head ;
}liste;

liste *creation()
{
    liste *liste_0 = (liste*)malloc(sizeof(liste));
    element *element_0 = (element*)malloc(sizeof(element));
    if (!liste_0 || !element_0)
       return(NULL);
    element_0->content= 0;
    element_0->next = NULL;
    element_0->precedent = NULL;
    return (liste_0);
}

void    InsertElement(liste *mon_liste, int x)
{
    element *element_1 = (element*)malloc(sizeof(element));
    if (!element_1)
    {
        element_1->content= x;
        element_1->next = mon_liste->head;
        mon_liste->head = element_1;
    }
}

void    InsertPos(liste *mon_liste, int pos, int x)
{
    element *element_actu = mon_liste->head;
    int i = 1;
    while (element_actu)
    {
        if (1 + (i++) == pos)
        {
            element *element_1 = (element*)malloc(sizeof(element));
            if (!element_1)
            {
                element_1->content= x;
                element_1->next = element_actu->next;
                element_actu->next = element_1;
            }
        }
        
    }
}

void    InsertFin(liste *mon_liste, int x)
{
    element *element_actu = mon_liste->head;
    while (element_actu->next)
        element_actu = element_actu->next;
    element *element_1 = (element*)malloc(sizeof(element));
    if (!element_1)
    {
        element_1->content= x;
        element_1->next = element_actu->next;
        element_actu->next = element_1;
    }
}

element   *Chercher(liste *mon_liste, int x)
{
    element *element_actu = mon_liste->head;
    while (element_actu->next)
        if (element_actu->content== x)
            return (element_actu);
        else        
            element_actu = element_actu->next;
    return(NULL);
}

void    *Suppression(liste *mon_liste, int x)
{
    element *element_actu = mon_liste->head;
    element *element_to_delete;
    while ((element_to_delete= Chercher(mon_liste, x)))
    {
        if (element_actu->next == element_to_delete)
        {
            element_actu->next = element_to_delete->next;
            free(element_to_delete);
        }
        else        
            element_actu = element_actu->next;
    }
}

void    Modification(liste *mon_liste, int old_x, int new_x)
{
    element *element_actu = mon_liste->head;
    while (element_actu->next)
        if (element_actu->content== old_x)
            element_actu->content= new_x;
        else        
            element_actu = element_actu->next;
}

void    Afficher(liste *mon_liste)
{
    element *pt = mon_liste->head;
    while (pt)
    {
        printf("[%d]=>",pt->content);
        pt = pt->next;
    }
    printf("NULL");
    while (pt)
    {
        printf("[%d]=>",pt->content);
        pt = pt->precedent;
    }
    printf("NULL");
}

int main()
{
    int r, x, y, p;
    liste *pl_1 = creation();
    do
    {
        printf("\npour insérer un élément au début :tapper 1:::");
        printf("\npour insérer un élément devant une position donnée :tapper 2:::");
        printf("\npour insérer un élément à la fin de la liste 3:::");
        printf("\npour chercher un élément donné :tapper 4:::");
        printf("\npour supprimer un élément donné :tapper 5:::");
        printf("\npour afficher la liste :tapper 6:::");
        printf("\n pour quiter : taper 0:::");
        scanf("%d",&r);
        switch (r)
        {
        case 1:
            printf("\nx= ");scanf("%d",&x);
            InsertElement(pl_1, x);
            break;
        case 2:
            printf("\nx= ");scanf("%d",&x);
            printf("\nposition= ");scanf("%d",&p);
            InsertPos(pl_1, p, x);
            break;
        case 3:
            printf("\nx= ");scanf("%d",&x);
            InsertFin(pl_1, x);
            break;
        case 4:
            printf("\nx= ");scanf("%d",&x);
            printf("\n%p",Chercher(pl_1, x));
            break;
        case 5:
            printf("\nx= ");scanf("%d",&x);
            Suppression(pl_1, x);
            break;
        case 6:
            Afficher(pl_1);
            break;
        default:
            printf("\nvotre choix est incorect");
            break;
        }
    } while (r);
    return (0);
    
}