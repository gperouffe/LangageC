#include "mat.h"
#include "vec.h"
#include "gauss.h"

void triangulation(T_Mat* pMat, T_Vec* pVec){}

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

void permuter(T_Mat* pMat, T_Vec* pVec, int p, int j){}