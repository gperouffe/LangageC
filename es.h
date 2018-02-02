#define pleine   1
#define diag     2
#define tridiag  3
#define triinf   4
#define trisup   5

#define addition 1
#define soustraction 2
#define multiplication 3
#define puissance 4
#define quitter 0



/*
 * fonction esSaisir
 * Description: Saisit  au clavier les elements d'une matrice definie
 * par l'utilisateur. La matrice en question est allouee et remplie
 * avec les valeurs definies par l'utilisateur.
 */
void esSaisir(T_Mat *pMat);

/*
 * fonction : esAfficher
 * Description : Affiche a l'ecran le contenu de la matrice reperee par pMAt
 */
void esAfficher(T_Mat *pMat);

int menu();
