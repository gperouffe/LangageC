#include <stdio.h>
#include "vec.h"
#include "mat.h"
#include "solveur.h"
#include "es.h"
#include "op.h"

int main(){

  printf("\n\n");
  printf("--------------------------------\n");
  printf("Operations Matricielles v1.01\n");
    printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");

  T_Mat mat1, mat2, mat3, mat4;
  T_Vec vec1, vec2;
  int exposant;

  char quit = 0,c;
  while(!quit){


    switch(menu()){
      case addition:
        printf("\n--------------------------------\n");
        printf("Premiere Matrice :\n");
        esSaisirDim(&mat1);
        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Seconde Matrice :\n");

        matAllouer(&mat2, mat1.NbLig, mat1.NbCol);
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
        esSaisirDim(&mat1);
        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Seconde Matrice :\n");
        matAllouer(&mat2, mat1.NbLig, mat1.NbCol);
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
        do{
          esSaisirDim(&mat2);
        } while(mat1.NbCol!=mat2.NbLig);
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
        esSaisirDim(&mat1);
        esSaisir(&mat1);

        printf("\n--------------------------------\n");
        printf("Exposant voulu: ");
        scanf(" %d", &exposant);

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
          esSaisirDim(&mat1);
          esSaisir(&mat1);
        } while(mat1.NbCol < mat1.NbLig);

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
          esSaisirDim(&mat1);
        } while(mat1.NbCol != mat1.NbLig);

        esSaisir(&mat1);

        do{
          printf("\n--------------------------------\n");
          printf("Vecteur :\n");
          vecSaisir(&vec1);
        } while(vec1.N != mat1.NbLig);

        vecAllouer(&vec2, mat1.NbCol);

        triangulation(&mat1, &vec1);
        remontee(&mat1, &vec1, &vec2);
        printf("\n--------------------------------\n");
        printf("Resultat :\n");
        vecAfficher(&vec2);
        break;

      case decompLU:

        do{
          printf("\n--------------------------------\n");
          printf("Matrice A :\n");
          esSaisirDim(&mat1);
        } while(mat1.NbCol != mat1.NbLig);

        esSaisir(&mat1);
        decompositionLU(&mat1, &mat2, &mat3, &mat4);
        printf("\n--------------------------------\n");
        printf("P :\n");
        esAfficher(&mat2);

        decompositionLU(&mat1, &mat2, &mat3, &mat4);
        printf("\n--------------------------------\n");
        printf("A :\n");
        esAfficher(&mat1);

        printf("\n--------------------------------\n");
        printf("L :\n");
        esAfficher(&mat3);

        printf("\n--------------------------------\n");
        printf("U :\n");
        esAfficher(&mat4);
        break;

      case quitter:
        quit = 1;
        break;
      default:
          while ((c = getchar()) != '\n' && c != EOF) { }
    }
    printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
  }
}
