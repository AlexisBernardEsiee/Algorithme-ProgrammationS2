#include <stdio.h>

/*
 * Première version : passage par valeur.
 * Elle est fournie pour montrer qu'elle ne fonctionne pas
 * pour échanger les variables de l'appelant.
 */
void echange_valeur(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * TODO
 * Compléter cette fonction pour échanger les deux entiers
 * pointés par a et b.
 */
void echange(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int x = 3;
    int y = 5;

    printf("=== Test de echange_valeur ===\n");
    printf("Avant : x = %d, y = %d\n", x, y);
    echange_valeur(x, y);
    printf("Apres : x = %d, y = %d\n", x, y);

    printf("\n=== Test de echange avec pointeurs ===\n");
    printf("Avant : x = %d, y = %d\n", x, y);
    echange(&x, &y);
    printf("Apres : x = %d, y = %d\n", x, y);

    return 0;
}
