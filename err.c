#include "err.h"

void errMsg(int num)
{
  char *Msg[] = {" tout va bien ",
                 "erreur 1: Les deux matrices n'ont pas les memes dimensions",
                 "erreur 2: le nombre de colonnes de la 1ere matrice est different du nombre de lignes de la 2eme",
                 "erreur 3: La matrice n'est pas carre"};
  
  printf("%d : %s\n", num, Msg[num]);
  exit (1);
}
