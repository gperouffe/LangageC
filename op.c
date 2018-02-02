#include "op.h"
#include "mat.h"
#include "err.h"
#include "es.h"

/*
 * fonction : opAddAlloc
 * Description : addition de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opAddAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int lig2 = pMat1->NbLig;
    int col1 = pMat1->NbCol;
    int col2 = pMat1->NbCol;
    if(lig1 != lig2 && col1 != col2){
        errMsg(DIFF_DIM);
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
    int lig2 = pMat1->NbLig;
    int col1 = pMat1->NbCol;
    int col2 = pMat1->NbCol;
    if(lig1 != lig2 || col1 != col2){
        errMsg(DIFF_DIM);
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
 * fonction : opMulAlloc
 * Description : multiplication de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int col1 = pMat1->NbCol;
    int lig2 = pMat1->NbLig;
    int col2 = pMat1->NbCol;
    if(col1 != lig2){
        errMsg(DIFF_DIM);
    }
    else{
        matAllouer(pMat3, lig1, col2);
        pMat3->Type = pleine;
        for(int i = 0; i < lig1; ++i)
        for(int j = 0; j < col2; ++j){
            double elt = 0;
            for(int k = 0; k < col1; ++k){
                elt += matAccElt(pMat1, i, k) * matAccElt(pMat2, k, j);
            }
            matModifElt(pMat3, i, j, elt);
        }
    }
}


/*
 * fonction : opMul
 * Description : multiplication de deux matrices SANS allocation de
 *	memoire pour la matrice resultat
 */
void opMul(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3){
    int lig1 = pMat1->NbLig;
    int col1 = pMat1->NbCol;
    int lig2 = pMat1->NbLig;
    int col2 = pMat1->NbCol;
    if(col1 != lig2){
        errMsg(DIFF_DIM);
    }
    else{
        for(int i = 0; i < lig1; ++i)
        for(int j = 0; j < col2; ++j){
            double elt = 0;
            for(int k = 0; k < col1; ++k){
                elt += matAccElt(pMat1, i, k) * matAccElt(pMat2, k, j);
            }
            matModifElt(pMat3, i, j, elt);
        }
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
void opPuis(T_Mat *pMat1,int Expo,T_Mat *pMat2){

}



/*
 * fonction : opNorme_1
 * Description : callul de la norme 1
 */

 double opNorme_1(T_Mat *pMat){

 }


/*
 * fonction : opNorme_2
 * Description : callul de la norme 2
 */

double opNorme_2(T_Mat *pMat){

}



/*
 * fonction : opNorme INF
 * Description : callul de la norme INF
 */
double opNorme_inf(T_Mat *pMat){

}
