#include "mat.h"
#include "es.h"
#include "err.h"
#include <stdio.h>

/*
 * fonction esSaisir
 * Description: Saisit  au clavier les elements d'une matrice definie
 * par l'utilisateur. La matrice en question est allouee et remplie
 * avec les valeurs definies par l'utilisateur.
 */
void esSaisir(T_Mat *pMat){
    int lig, col;

    char validDim=0;
    while(!validDim){
        printf("Nombre de lignes: ");
        scanf("%d", &lig);
        printf("Nombre de colonnes: ");
        scanf("%d", &col);
        if(lig <= 0 && col <= 0){
            printf("Les dimensions sont invalides. \n");
        }
        else{
            validDim = 1;
        }
    }

    matAllouer(&pMat, lig, col);

    int type=0;
    char validType=0;
    while(!validType){
        printf("Type de la matrice (pleine = 1, diag = 2, tridiag = 3, triinf = 4, trisup = 5): ");
        scanf("%d", &type);
        if(type == 1){
            validType = 1;
        }
        if(type >= 2 && type <= 5){
            if(lig == col)
                validType = 1;
            else
                errMsg(NOT_SQUARE);
        }
        if(type < 1 || type >5){
            printf("Veuillez entrer un type valide.\n");
        }
    }
    pMat->Type = type;


    double elt;
    for(int i = 0; i < pMat->NbLig; ++i)
    for(int j = 0; j < pMat->NbCol; ++j){
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
    printf("%d\n",pMat->NbLig);
}

/*
 * fonction : esAfficher
 * Description : Affiche a l'ecran le contenu de la matrice reperee par pMAt
 */
void esAfficher(T_Mat *pMat){
    printf("%d\n",pMat->NbLig);
    for(int i = 0; i < pMat->NbLig; ++i){
        for(int j = 0; j < pMat->NbCol; ++j){
            printf("%lf", matAccElt(pMat, i, j));
        }
        printf("\n");
    }
}

int menu(){

  int entry;
  printf("\nChoisissez une operation\n");
  printf("\n\t1 - Addition\t\t\t2 - Soustraction");
  printf("\n\t3 - Multiplication\t\t4 - Puissance");
  printf("\n\t0 - Quitter");

  printf("\n\n----->");
  scanf("%d",&entry);

  switch(entry){
    case addition:
    case soustraction:
    case multiplication:
    case puissance:
    case quitter:
            return entry;
            break;
    default:printf("Entree non reconnues, veuillez recommencer");
            return -1;
            break;
  }
}
