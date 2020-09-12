/*
Soit une liste simplement chainée d’éléments composés. On suppose ces éléments des points
d’un plan cartésien. Chaque point est identifié par une ordonnée (y) et une abscisse (x) de type
float.
1- Définir la structure correspondante à ce type composé.
2- On veut gérer cette liste par les fonctions suivantes.
• Creation(), pour créer la liste.
• InsertDeb(), pour insérer un élément au début.
• InsertPos(), pour insérer un élément devant une position donnée.
• InsertFin(), pour insérer un élément à la fin de la liste.
• Chercher(), pour chercher un élément donné.
• Suppression(), pour supprimer un élément donné. On ne peut supprimer que
des éléments trouvés par la fonction Chercher().
• Modification(), pour modifier un élément donné. On ne peut supprimer que
des éléments trouvés par la fonction Chercher().
• Afficher(), pour afficher la liste.
3- Dans la fonction main(), vous créez un menu interactif illustrant les choix numérotés
qu’on peut faire. Prenez en considération qu’on ne peut appliquer aucune des
fonctions que si la liste est déjà créée.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
    struct point *next; 
}point;


typedef struct plan
{
    point *head ;
}plan;

plan *creation()
{
    plan *plan_0 = (plan*)malloc(sizeof(plan));
    point *point_0 = (point*)malloc(sizeof(point));
    if (!plan_0 || !point_0)
       return(NULL);
    point_0->x = 0;
    point_0->y = 0;
    point_0->next = NULL;
    return (plan_0);
}

void    InsertDeb(plan *mon_plan, int x, int y)
{
    point *point_1 = (point*)malloc(sizeof(point));
    if (!point_1)
    {
        point_1->x = x;
        point_1->y = y;
        point_1->next = mon_plan->head;
        mon_plan->head = point_1;
    }
}

void    InsertPos(plan *mon_plan, int pos, int x, int y)
{
    point *point_actu = mon_plan->head;
    int i = 1;
    while (point_actu)
    {
        if (1 + (i++) == pos)
        {
            point *point_1 = (point*)malloc(sizeof(point));
            if (!point_1)
            {
                point_1->x = x;
                point_1->y = y;
                point_1->next = point_actu->next;
                point_actu->next = point_1;
            }
        }
        
    }
}

void    InsertFin(plan *mon_plan, int x, int y)
{
    point *point_actu = mon_plan->head;
    while (point_actu->next)
        point_actu = point_actu->next;
    point *point_1 = (point*)malloc(sizeof(point));
    if (!point_1)
    {
        point_1->x = x;
        point_1->y = y;
        point_1->next = point_actu->next;
        point_actu->next = point_1;
    }
}

point   *Chercher(plan *mon_plan, int x, int y)
{
    point *point_actu = mon_plan->head;
    while (point_actu->next)
        if (point_actu->x == x && point_actu->y == y )
            return (point_actu);
        else        
            point_actu = point_actu->next;
    return(NULL);
}

void    *Suppression(plan *mon_plan, int x, int y)
{
    point *point_actu = mon_plan->head;
    point *point_to_delete;
    while ((point_to_delete= Chercher(mon_plan, x, y)))
    {
        if (point_actu->next == point_to_delete)
        {
            point_actu->next = point_to_delete->next;
            free(point_to_delete);
        }
        else        
            point_actu = point_actu->next;
    }
}

void    Modification(plan *mon_plan, int old_x, int old_y, int new_x, int new_y)
{
    point *point_actu = mon_plan->head;
    while (point_actu->next)
        if (point_actu->x == old_x && point_actu->y == old_y )
        {
            point_actu->x = new_x;
            point_actu->y = new_y;
        }
        else        
            point_actu = point_actu->next;
}

void    Afficher(plan *mon_plan)
{
    point *pt = mon_plan->head;
    while (pt)
    {
        printf("[%d, %d]=>",pt->x,pt->y);
    }
    printf("NULL");
}
int main()
{
    int r, x, y, p;
    plan *pl_1 = creation();
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
            printf("\ny= ");scanf("%d",&y);
            InsertDeb(pl_1, x, y);
            break;
        case 2:
            printf("\nx= ");scanf("%d",&x);
            printf("\ny= ");scanf("%d",&y);
            printf("\nposition= ");scanf("%d",&p);
            InsertPos(pl_1, p, x, y);
            break;
        case 3:
            printf("\nx= ");scanf("%d",&x);
            printf("\ny= ");scanf("%d",&y);
            InsertFin(pl_1, x, y);
            break;
        case 4:
            printf("\nx= ");scanf("%d",&x);
            printf("\ny= ");scanf("%d",&y);
            printf("\n%p",Chercher(pl_1, x, y));
            break;
        case 5:
            printf("\nx= ");scanf("%d",&x);
            printf("\ny= ");scanf("%d",&y);
            Suppression(pl_1, x, y);
            break;
        case 6:
            Afficher(pl_1);
            break;
        default:
            printf("\nchoix incorect");
            break;
        }
    } while (r);
    return (0);
    
}