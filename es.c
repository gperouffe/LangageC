#include "mat.h"
#include "vec.h"
#include "es.h"
#include "err.h"
#include <stdio.h>
#include <string.h>

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

    matAllouer(pMat, lig, col);

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
}

/*
 * fonction esSaisir
 * Description: Saisit  au clavier les elements d'un vecteur
 * par l'utilisateur. Le vecteur en question est alloue et rempli
 * avec les valeurs definies par l'utilisateur.
 */
void vecSaisir(T_Vec *pVec){
    int N;

    char validDim=0;
    while(!validDim){
        printf("Nombre de lignes: ");
        scanf("%d", &N);
        if(N <= 0){
            printf("Les dimensions sont invalides. \n");
        }
        else{
            validDim = 1;
        }
    }

    vecAllouer(pVec, N);

    double elt;
    for(int j = 0; j < pVec->N; ++j){
            printf("Vec[%d]=", j);
            scanf("%lf", &elt);
            vecModifElt(pVec, j, elt);
    }
}

/*
 * fonction : esAfficher
 * Description : Affiche a l'ecran le contenu de la matrice reperee par pMAt
 */
void esAfficher(T_Mat *pMat){

    char typeMat[25];

    switch(pMat->Type){
      case pleine:
      {
        strcpy(typeMat,"pleine");
        break;
      }

      case diag:
      {
        strcpy(typeMat,"diagonale");
        break;
      }

      case tridiag:
      {
        strcpy(typeMat,"tridiagonale");
        break;
      }

      case triinf:
      {
        strcpy(typeMat,"triangulaire inferieure");
        break;
      }

      case trisup:
      {
        strcpy(typeMat,"triangulaire superieure");
        break;
      }

      default:
      {
        strcpy(typeMat,"problematique");
        break;
      }
    }


    printf("Matrice de type %s.\n",typeMat);

    for(int i = 0; i < pMat->NbLig; ++i){
        for(int j = 0; j < pMat->NbCol; ++j){
            printf("%.3lf\t", matAccElt(pMat, i, j));
        }
        printf("\n");
    }
}


/*
 * fonction : esAfficher
 * Description : Affiche a l'ecran le contenu du vecteur représenté par pVec
 */
void vecAfficher(T_Vec *pVec){
    for(int i = 0; i < pVec->N; ++i){
        printf("%.3lf\n", vecAccElt(pVec, i));
    }
}

int menu(){

  int entry;
  printf("\nChoisissez une operation\n");
  printf("\n\t1 - Addition\t\t\t2 - Soustraction");
  printf("\n\t3 - Multiplication\t\t4 - Puissance");
  printf("\n\t5 - Triangulariser\t\t6 - Resoudre(Gauss)");
  printf("\n\t7 - Decomposition LU");
  printf("\n\t0 - Quitter");

  printf("\n\n----->");
  scanf("%d",&entry);

  switch(entry){
    case addition:
    case soustraction:
    case multiplication:
    case puissance:
    case triangulariser:
    case resoudre:
    case decompLU:
    case quitter:
        return entry;
        break;
    default:
        printf("Entree non reconnues, veuillez recommencer");
        fseek(stdin,0,SEEK_END);
        return -1;
        break;
  }
}
