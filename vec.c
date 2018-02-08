#include "vec.h"
#include <stdlib.h>

/*
 * fonction vecAllouer
 * Description: Initialise la structure reperee par pVec
 *   pour qu'elle puisse contenir un vecteur de N éléments
 */
void vecAllouer(T_Vec *pVec, int N){
    pVec->N = N;
    pVec->Elts = malloc(sizeof(double)*N);
}

/*
 * fonction vecAccElt
 * Description: retourne la valeur de  l'element en position i
 *    du vecteur pointe par pVec
 */
double vecAccElt(T_Vec *pVec, int i){
    return pVec->Elts[i];
}

/*
 * fonction vecModifElt
 * Description: Affecte Val a l'element en position i du 
 * vecteur repere par pVec
 */
void vecModifElt(T_Vec *pVec, int i, double Val){
    pVec->Elts[i] = Val;
}

/*
 * fonction : vecLiberer
 * Description : Affiche a l'ecran le contenu du vecteur repere par pVec
 */
void vecLiberer(T_Vec *pVec){
    if(pVec->Elts!=NULL){
        free(pVec->Elts);
    }
}

/*
 * fonction : vecInit
 * Description : initialise un vecteur deja cree a une valeur Val donnee
 */
void matInit(T_Vec* pVec, double Val){
    for(int i = 0; i < pVec->N; ++i){
        vecModifElt(pVec, i, Val);
    }
}