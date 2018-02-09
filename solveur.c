#include "mat.h"
#include "op.h"
#include "vec.h"
#include "solveur.h"
#include <math.h>
#include <stdio.h>

void triangulation(T_Mat* pMat, T_Vec* pVec){

  int dernierPivot = 0;

  for(int j = 0;j<pMat->NbCol;j++){

    double max = 0;
    int maxIndex = 0;

    for(int i = j; i<pMat->NbLig;i++){
      if(fabs(matAccElt(pMat,i,j))>max){
        max = matAccElt(pMat,i,j);
        maxIndex=i;
      }
    }
    if(max!=0){

      //On divise la ligne par le max => pivot = 1 et le reste est <1
      for(int i = 0;i<pMat->NbCol;i++){
        matModifElt(pMat,maxIndex,i,(matAccElt(pMat,maxIndex,i)/max));
      }
      vecModifElt(pVec,maxIndex,(vecAccElt(pVec,maxIndex)/max));

      if(maxIndex!=dernierPivot){
        sysEchangeLig(pMat,pVec,maxIndex,dernierPivot);
      }

      for(int i = 0;i<pMat->NbLig;i++){
        if(i!=dernierPivot){
          double elt = matAccElt(pMat,i,j);
          if(elt){
            vecModifElt(pVec,i,(vecAccElt(pVec, i)-elt*vecAccElt(pVec,dernierPivot)));
            for(int k = 0;k<pMat->NbCol;k++)
              matModifElt(pMat,i,k,(matAccElt(pMat,i,k)-elt*matAccElt(pMat,dernierPivot,k)));

          }
        }
      }
      dernierPivot++;
    }
  }
}

void remontee(T_Mat* pMat, T_Vec* pVec, T_Vec* pSolu){
    int N = pVec->N;
    double xi;
    for(int i = N-1; i >= 0; --i){
        double aij_xj = 0;
        for(int j = i+1; j < N; ++j){
            aij_xj += matAccElt(pMat, i, j) * vecAccElt(pSolu, j);
        }
        xi = (vecAccElt(pVec, i) - aij_xj) / matAccElt(pMat, i, i);
        vecModifElt(pSolu, i, xi);
    }
}

void sysEchangeLig(T_Mat* pMat, T_Vec* pVec, int p, int j){

  double temp=0;
  for(int c = 0;c<pMat->NbCol;++c){

    temp=matAccElt(pMat,p,c);
    matModifElt(pMat,p,c,matAccElt(pMat,j,c));
    matModifElt(pMat,j,c,temp);

    temp=vecAccElt(pVec,p);
    vecModifElt(pVec,p,vecAccElt(pVec,j));
    vecModifElt(pVec,j,temp);
    }
}

void matEchangeLig(T_Mat* pMat, int p, int j){

  double temp=0;
  for(int c = 0;c<pMat->NbCol;++c){

    temp=matAccElt(pMat,p,c);
    matModifElt(pMat,p,c,matAccElt(pMat,j,c));
    matModifElt(pMat,j,c,temp);
    }
}

void permutation(T_Mat* pMat, T_Mat* pPermut){

    matUnite(pPermut,pMat->NbLig);
    for(int i = 0;i<pMat->NbCol;i++){

      int max_j=0;
      for(int j = i; j<pMat->NbLig;j++){
        if(fabs(matAccElt(pMat,j,i))>fabs(matAccElt(pMat,max_j,i)))
          max_j=j;
      }

      if(max_j!!=i){
        matEchangeLig(pPermut,max_j,i);
      }
    }



}

void decompositionLU(T_Mat* pMat, T_Mat* pPermut, T_Mat* pL, T_Mat* pU){

  int N = pMat->NbLig;

  matAllouer(pPermut, N, N);
  matUnite(pL, N);
  matAllouer(pU, N, N);
  matInit(pU, 0);

  permutation(pMat, pPermut);

  T_Mat Aprime;

  opMulAlloc(pPermut, pMat, &Aprime);

  for(int i = 0; i < N; ++i)
  for(int j = 0; j < N; ++j){
    double sum = 0;
    for(int k = j; k < N; ++k){
      sum += matAccElt(pL, j, k) * matAccElt(pU, k, i);
    }
    if(j <= i){
      matModifElt(pU, j, i, matAccElt(&Aprime, j, i) - sum);
    }
    if(j >= i){
      matModifElt(pL, j, i, (matAccElt(&Aprime, j, i) - sum)/ matAccElt(pU, i, i));
    }
  }


}
