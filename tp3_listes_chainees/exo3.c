/*
Le but de cet exercice est d’implémenter des opérations sur des polynômes par des listes
chaînées. On représente un polynôme par une liste chaînée. Chaque cellule de la listecorrespond à un monôme, avec son coefficient et son exposant. Si le coefficient est nul un tel
monôme ne doit pas être pris en considération.
Par exemple, sur la figure ci-dessous, on représente la liste chaînée correspondant au
polynôme 10x + 5x − 3x + 5.
1- Implémenter les fonctions suivantes :
- Creer_Pol() qui permet de créer un polynôme,
- AjoutMon() qui ajoute un monôme à un polynôme en respectant l’ordre
décroissant des exposants.
- AddPol() qui retourne la somme de deux polynômes en respectant aussi l’ordre
des exposants.
- DerivPol() qui retourne la dérivée d’un polynôme.
- PrimPol() qui retourne la primitive d’un polynôme.
- Affiche() qui afficher un polynôme.
2- Tester dans le main() avec un menu interactif.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct monome
{
   double coeff;
   int   exposent;
   struct monome *next;
   
}monome;

typedef struct polynome
{
    monome *first;
}polynome;

polynome *Creer_Pol()
{
    polynome *p = (polynome*)malloc(sizeof(polynome));
    monome *m = (monome*)malloc(sizeof(monome));
    if (!p || !m)
       return(NULL);
    m->coeff = 0;
    m->exposent = 0;
    m->next = NULL;
    p->first = m;
    return (p);
}

void    AjoutMon(polynome *p, double coeff, int exposent)
{
    monome *m = (monome*)malloc(sizeof(monome);
    m = p->first;
    while (m)
    {
        if(m->exposent == exposent)
            m->exposent += exposent;
        else if (m->exposent < exposent)
        {
            monome *new_m = (monome*)malloc(sizeof(monome));
            if (new_m)
            {
                new_m->coeff = m->coeff;
                new_m->exposent = m->exposent;
                new_m->next = m->next;
                m->next = new_m;
                m->coeff = coeff;
                m->exposent = exposent;
            }
            break;

        }
        else
            m =m->next; 
    }
}

polynome    *AddPol(polynome *p1,polynome *p2)
{
    polynome *p = Creer_Pol();
    monome *m = (monome*)malloc(sizeof(monome));
    m = p1->first;
    while (m)
    {
        AjoutMon(p, m->coeff, m->exposent);
        m = m->next;
    }
    m = p2->first;
    while (m)
    {
        AjoutMon(p, m->coeff, m->exposent);
        m = m->next;
    }
    return (p);
}

polynome    DerivPol(polynome *p)
{
    polynome *p_d = Creer_Pol();
    monome *m = (monome*)malloc(sizeof(monome));
    m = p->first;
    while (m)
    {
        AjoutMon(p_d, m->coeff * m->exposent , m->exposent -1);
        m = m->next;
    }
    return (p_d);
}

polynome    *PrimPol(polynome *p)
{
    polynome *p_p = Creer_Pol();
    monome *m = (monome*)malloc(sizeof(monome));
    m = p->first;
    while (m)
    {
        AjoutMon(p_p, m->coeff / m->exposent , m->exposent + 1);
        m = m->next;
    }
    return (p_p);
}

void    Affiche(polynome *p)
{
    monome *m = (monome*)malloc(sizeof(monome));
    m = p->first;
    while (m)
    {
        printf("+%fX^%d ",m->coeff, m->exposent);
        m = m->next;
    }
    printf("\n");
}