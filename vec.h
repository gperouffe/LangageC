#ifndef VEC_H
#define VEC_H

typedef struct{
    int N;
    double *Elts;
} T_Vec;

/*
 * fonction vecAllouer
 * Description: Initialise la structure reperee par pVec
 *   pour qu'elle puisse contenir un vecteur de N éléments
 */
void vecAllouer(T_Vec *pVec, int N);

/*
 * fonction vecAccElt
 * Description: retourne la valeur de  l'element en position i
 *    du vecteur pointe par pVec
 */
double vecAccElt(T_Vec *pVec, int i);

/*
 * fonction vecModifElt
 * Description: Affecte Val a l'element en position i du 
 * vecteur repere par pVec
 */
void vecModifElt(T_Vec *pVec, int i, double Val);

/*
 * fonction : vecLiberer
 * Description : Affiche a l'ecran le contenu du vecteur repere par pVec
 */
void vecLiberer(T_Vec *pVec);

/*
 * fonction : vecInit
 * Description : initialise un vecteur deja cree a une valeur Val donnee
 */
void matInit(T_Mat *pVec, double Val);

#endif