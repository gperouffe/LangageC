#include "mat.h"
#include "op.h"
#include "err.h"
#include "es.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * fonction : opAddAlloc
 * Description : addition de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opAddAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int lig2 = pMat2->NbLig;
    int col1 = pMat1->NbCol;
    int col2 = pMat2->NbCol;
    if(lig1 != lig2 || col1 != col2){
        errMsg(DIFF_DIM);
        pMat3=NULL;
    }
    else{
        matAllouer(pMat3, lig1, col1);
        pMat3->Type = pleine;
        for(int i = 0; i < lig1; ++i)
        for(int j = 0; j < col1; ++j){
            matModifElt(pMat3, i, j, matAccElt(pMat1,i,j) + matAccElt(pMat2,i,j));
        }
    }
}


/*
 * fonction : opSubAlloc
 * Description : soustraction de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opSubAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int lig2 = pMat2->NbLig;
    int col1 = pMat1->NbCol;
    int col2 = pMat2->NbCol;
    if(lig1 != lig2 || col1 != col2){
        errMsg(DIFF_DIM);
        pMat3=NULL;
    }
    else{
        matAllouer(pMat3, lig1, col1);
        pMat3->Type = pleine;
        for(int i = 0; i < lig1; ++i)
        for(int j = 0; j < col1; ++j){
            matModifElt(pMat3, i, j, matAccElt(pMat1,i,j) - matAccElt(pMat2,i,j));
        }
    }
}


/*
 * fonction : opMulA"lloc
 * Description : multiplication de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int lig2 = pMat2->NbLig;
    int col1 = pMat1->NbCol;
    int col2 = pMat2->NbCol;
    if(col1 != lig2){
        errMsg(COL_DIFF_LIG);
        pMat3=NULL;
    }
    else{
        matAllouer(pMat3, lig1, col2);
        pMat3->Type = pleine;
        opMul(pMat1,pMat2,pMat3);
    }
}


/*
 * fonction : opMul
 * Description : multiplication de deux matrices SANS allocation de
 *	memoire pour la matrice resultat
 */
void opMul(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int lig2 = pMat2->NbLig;
    int col1 = pMat1->NbCol;
    int col2 = pMat2->NbCol;
    for(int i = 0; i < lig1; ++i)
    for(int j = 0; j < col2; ++j){
        double elt = 0;
        for(int k = 0; k < col1; ++k){
            elt += matAccElt(pMat1, i, k) * matAccElt(pMat2, k, j);
        }
        matModifElt(pMat3, i, j, elt);
    }
}

/*
 * fonction : opMulScalAlloc
 * Description : multiplication d'une matrice par scalaire AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulScalAlloc(T_Mat *pMat1,double scal,T_Mat *pMat2){
    int lig1 = pMat1->NbLig;
    int col1 = pMat1->NbCol;
    matAllouer(pMat2, lig1, col1);
    pMat2->Type = pleine;
    for(int i = 0; i < lig1; ++i)
    for(int j = 0; j < col1; ++j){
        matModifElt(pMat2, i, j, matAccElt(pMat1, i, j) * scal);
    }
}


/*
 * fonction : opPuis
 * Description : callul la puissance d'une  matrice
 */
void opPuis(T_Mat *pMat1, int Expo, T_Mat *pMat2){
    printf("%d\n", Expo);
    int lig = pMat1->NbLig;
    int col = pMat1->NbCol;
    if(lig != col){
        errMsg(NOT_SQUARE);
        pMat2=NULL;
    }
    else{
        matCopy(pMat1, pMat2);
        T_Mat* temp = malloc(sizeof(T_Mat));
        matAllouer(temp, lig, col);
        for(int i = 1; i < Expo; ++i){
            opMul(pMat2, pMat1, temp);

            double* result = temp->Elts;
            temp->Elts = pMat2->Elts;
            pMat2->Elts = result;
        }
        matLiberer(temp);
    }
}



/*
 * fonction : opNorme_1
 * Description : callul de la norme 1
 */
 double opNorme_1(T_Mat *pMat){
   double result = 0;

   for(int i = 0; i < (pMat->NbLig);i++){
     for(int j = 0; j < (pMat->NbCol);j++){
       result+=fabs(matAccElt(pMat,i,j));
     }
   }

   return result;
 }


/*
 * fonction : opNorme_2
 * Description : callul de la norme 2
 */

double opNorme_2(T_Mat *pMat){
  double result = 0;
  double temp = 0;

  for(int i = 0; i < (pMat->NbLig);i++){
    for(int j = 0; j < (pMat->NbCol);j++){
      temp=(matAccElt(pMat,i,j));
      result+=temp*temp;
    }
  }

  return sqrt(result);
}



/*
 * fonction : opNorme INF
 * Description : callul de la norme INF
 */
double opNorme_inf(T_Mat *pMat){

  double result = 0;
  double temp;

  for(int i = 0; i < (pMat->NbLig);i++){
    for(int j = 0; j < (pMat->NbCol);j++){

      temp = fabs(matAccElt(pMat,i,j));
      if(temp>result){
        result = temp;

      }
    }
  }

  return result;

}
