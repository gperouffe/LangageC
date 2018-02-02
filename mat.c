#include <stdlib.h>
#include "mat.h"
#include "es.h"

/*
 * fonction matAllouer
 * Description: Initialise la structure reperee par pMat
 *   pour qu'elle puisse contenir une matrice ayant
 *   Nblig lignes et NbCol colones
 */
void matAllouer(T_Mat **pMat, int NbLig, int NbCol){
    *pMat = malloc(sizeof(T_Mat));
    (*pMat)->Type = pleine;
    (*pMat)->NbLig = NbLig;
    (*pMat)->NbCol = NbCol;
    (*pMat)->Elts = malloc(sizeof(double)*NbLig*NbCol);
}

/*
 * fonction matNbLig
 * Description: retourne le nombre de lignes de la matrice
 *   reperee par pMat
 */
int matNbLig(T_Mat *pMat){
  return pMat->NbLig;
}

/*
 * fonction matNbCol
 * Description: retourne le nombre de colonnes de la matrice
 *   reperee par pMat
 */
int matNbCol(T_Mat *pMat){
  return pMat->NbCol;
}

/*
 * fonction matAccElt
 * Description: retourne la valeur de  l'element en position (Lig,Col)
 *    de la matrice pointee par pMat
 */
double matAccElt(T_Mat *pMat,int Lig, int Col){
  int x = Lig*(pMat->NbCol)+Col;
  return (pMat->Elts[x]);
}

/*
 * fonction matModifElt
 * Description: Affecte Val a l'element en position (Lig,Col) de
 *  la matrice reperee par pMat
 */
void matModifElt(T_Mat *pMat, int Lig, int Col,double Val){
  int x = Lig*(pMat->NbCol)+Col;
  pMat->Elts[x] = Val;
}


/*
 * fonction : matLiberer
 * Description : Libere la memoire stockee par la T_Mat
 */
void matLiberer(T_Mat *pMat){
  if(pMat!=NULL){
    free(pMat->Elts);
    free(pMat);
  }
}


/*
 * fonction : matUnite
 * Description : cree une matrice unite de dimension Dim reperer par pMat
 */
void matUnite(T_Mat *pMat, int Dim){
  pMat->Type = 2;
  pMat->NbLig = Dim;
  pMat->NbCol = Dim;
  matInit(pMat, 0);
  for(int i = 0; i<Dim;i++){
    int x = i*(pMat->NbCol)+i;
    pMat->Elts[x] = 1;
  }
}


/*
 * fonction : matInit
 * Description : initialise une matrice deja creee a une valeur Val donnee
 */
void matInit(T_Mat *pMat, double Val){
  for(int i = 0;i<(pMat->NbLig)*(pMat->NbCol);i++){
    pMat->Elts[i]=Val;
  }
}


/*
 * fonction : matCopy
 * Description : copie une matrice, repere par pMat1 dans upMat1->NbLigne autre
 *	reperee par pMat2
 */
void matCopy(T_Mat *pMat1, T_Mat *pMat2){

  matAllouer(&pMat2,pMat1->NbLig,pMat1->NbCol);
  (pMat2->Type)=(pMat1->Type);
  (pMat2->NbCol)=(pMat1->NbCol);
  (pMat2->NbLig)=(pMat1->NbLig);

  for(int i = 0;i<(pMat1->NbLig)*(pMat1->NbCol);i++){
    (pMat2->Elts[i])=(pMat1->Elts[i]);
  }

}
