#include <stdio.h>
#include "vec.h"
#include "mat.h"
#include "gauss.h"
#include "es.h"
#include "op.h"

int main(){

  printf("\n\n");
  printf("--------------------------------\n");
  printf("Operations Matricielles v1.01\n");
    printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");

  T_Mat mat1, mat2, mat3;
  T_Vec vec1, vec2;
  int x = 0, exposant;

  while(x=menu()){



    switch(x){
      case addition:
        printf("\n--------------------------------\n");
        printf("Premiere Matrice :\n");

        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Seconde Matrice :\n");
        esSaisir(&mat2);

        opAddAlloc(&mat1, &mat2, &mat3);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        esAfficher(&mat3);

        matLiberer(&mat1);
        matLiberer(&mat2);
        matLiberer(&mat3);
        break;


      case soustraction:

        printf("\n--------------------------------\n");
        printf("Premiere Matrice :\n");

        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Seconde Matrice :\n");
        esSaisir(&mat2);

        opSubAlloc(&mat1, &mat2, &mat3);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        esAfficher(&mat3);

        matLiberer(&mat1);
        matLiberer(&mat2);
        matLiberer(&mat3);
        break;


      case multiplication:

        printf("\n--------------------------------\n");
        printf("Premiere Matrice :\n");

        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Seconde Matrice :\n");
        esSaisir(&mat2);

        opMulAlloc(&mat1, &mat2, &mat3);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        esAfficher(&mat3);

        matLiberer(&mat1);
        matLiberer(&mat2);
        matLiberer(&mat3);
        break;


      case puissance:

        printf("\n--------------------------------\n");
        printf("Premiere Matrice :\n");

        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Exposant voulu: ");
        scanf("%d", &exposant);

        opPuis(&mat1, exposant, &mat2);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        esAfficher(&mat2);

        matLiberer(&mat1);
        matLiberer(&mat2);
        break;


      case triangulariser:

        do{
          printf("\n--------------------------------\n");
          printf("Matrice :\n");
          esSaisir(&mat1);
        } while(mat1.NbCol != mat1.NbLig);

        vecAllouer(&vec1, mat1.NbLig);
        vecInit(&vec1, 1);

        triangulation(&mat1, &vec1);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        esAfficher(&mat1);
        break;


      case resoudre:

        do{
          printf("\n--------------------------------\n");
          printf("Matrice :\n");
          esSaisir(&mat1);
        } while(mat1.NbCol != mat1.NbLig);

        do{
          printf("\n--------------------------------\n");
          printf("Vecteur :\n");
          vecSaisir(&vec1);
        } while(vec1.N != mat1.NbLig);

        vecAllouer(&vec2, vec1.N);

        remontee(&mat1, &vec1, &vec2);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        vecAfficher(&vec2);
        break;

      default:break;
    }
    printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
  }
}
