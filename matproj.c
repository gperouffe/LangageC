#include <stdio.h>
#include "mat.h"
#include "op.h"
#include "es.h"

int main(){

  printf("\n\n");
  printf("--------------------------------\n");
  printf("Operations Matricielles v1.01\n");
  printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");

  T_Mat mat1, mat2, mat3;
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

      default:break;
    }
  }
}
