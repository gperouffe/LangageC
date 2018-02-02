#include "op.h"
#include "mat.h"
#include "es.h"
#include "err.h"
#include <math.h>

/*
 * fonction : opAddAlloc
 * Description : addition de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opAddAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){

}


/*
 * fonction : opSubAlloc
 * Description : soustraction de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opSubAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){

}


/*
 * fonction : opMulA"lloc
 * Description : multiplication de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){

}


/*
 * fonction : opMul
 * Description : multiplication de deux matrices SANS allocation de
 *	memoire pour la matrice resultat
 */
void opMul(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){

}

/*
 * fonction : opMulScalAlloc
 * Description : multiplication d'une matrice par scalaire AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulScalAlloc(T_Mat *pMat1,double scal,T_Mat *pMat2){

}


/*
 * fonction : opPuis
 * Description : callul la puissance d'une  matrice
 */
void opPuis(T_Mat *pMat1,int Expo,T_Mat *pMat2){

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
