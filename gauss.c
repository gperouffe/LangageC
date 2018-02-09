#include "mat.h"
#include "vec.h"
#include "gauss.h"
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
        echangeLig(pMat,pVec,maxIndex,dernierPivot);
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

void echangeLig(T_Mat* pMat, T_Vec* pVec, int p, int j){

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
