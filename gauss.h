#ifndef GAUSS_H
#define GAUSS_H

void triangulation(T_Mat* pMat, T_Vec* pVec);

void remontee(T_Mat* pMat, T_Vec* pVec, T_Vec* pSolu);

void echangeLig(T_Mat* pMat, T_Vec* pVec, int p, int j);

#endif
