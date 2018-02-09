#ifndef SOLVEUR_H
#define SOLVEUR_H

void triangulation(T_Mat* pMat, T_Vec* pVec);

void remontee(T_Mat* pMat, T_Vec* pVec, T_Vec* pSolu);

void echangeLig(T_Mat* pMat, T_Vec* pVec, int p, int j);

void permutation(T_Mat* pMat, T_Mat* pPermut);

void decompositionLU(T_Mat* pMat, T_Mat* pPermut, T_Mat* pL, T_Mat* pU);

#endif
