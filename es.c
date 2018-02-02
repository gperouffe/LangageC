#include "mat.h"
#include "es.h"
#include "err.h"

/*
 * fonction esSaisir
 * Description: Saisit  au clavier les elements d'une matrice definie
 * par l'utilisateur. La matrice en question est allouee et remplie
 * avec les valeurs definies par l'utilisateur.
 */
void esSaisir(T_Mat *pMat){
    double elt;
    for(int i = 0; i < pMat->NbLig; ++i)
    for(int j = 0; i < pMat->NbCol; ++j){
        char askForElt = 0;
        switch(pMat->Type){
            case pleine:
                askForElt = 1;
                break;
            case diag:
                if(i==j){
                    askForElt = 1;
                }
                break;
            case tridiag:
                if(i==j || i+1 == j || i-1 == j){
                    askForElt = 1;
                }
                break;
            case triinf:
                if(i >= j){
                    askForElt = 1;
                }
                break;
            case trisup:
                if(i <= j){
                    askForElt = 1;
                }
                break;
        }
        if(askForElt){
            printf("Mat[%d][%d]=", i, j);
            scanf("%lf", &elt);
            matModifElt(pMat, i, j, elt);
        }            
        else{
            matModifElt(pMat, i, j, 0);
        }
    }
}

/*
 * fonction : esAfficher
 * Description : Affiche a l'ecran le contenu de la matrice reperee par pMAt
 */
void esAfficher(T_Mat *pMat){
    for(int i = 0; i < pMat->NbLig; ++i){
        for(int j = 0; i < pMat->NbCol; ++j){
            printf("%lf", matAccElt(pMat, i, j));
        }
        printf("\n");
    }
}
