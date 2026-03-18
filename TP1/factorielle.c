#include <stdio.h>

/* int factorielle_iterative(int n)
 * calcule la factorielle de n
 * Principe : accumulation des produits des n premiers nombres
 * arguments : n entier positif
 * retour : factorielle de n si n>=0
 *          1 si n est negatif
 */
int factorielle_iterative(int n) {
    int i, p = 1;
    for (i = 1; i <= n; ++i)
        p *= i;
    return p;
}

/* int factorielle_recursive(int n)
 * calcule la factorielle de n
 * Principe : F(n)=1 si n=0, F(n)=n*F(n-1) si n>0
 * arguments : n entier positif
 * retour : factorielle de n si n>=0
 *          1 si n est negatif
 */
int factorielle_recursive(int n) {
    if (n <= 0)
        return 1;
    else
        return n * factorielle_recursive(n - 1);
}

void afficher_table_factorielles(void) {
    int i;

    printf(" n | factorielle_iterative | factorielle_recursive\n");
    printf("---+-----------------------+----------------------\n");
    for (i = 1; i <= 15; ++i) {
        printf("%2d | %21d | %20d\n",
               i,
               factorielle_iterative(i),
               factorielle_recursive(i));
    }
}

int main(void) {
    int n;

    do {
        printf("\nEntrez un entier positif.\n");
        printf("  0  : terminer\n");
        printf(" -1  : afficher les factorielles de 1 a 15\n");
        printf("Votre choix : ");
        scanf("%d", &n);

        if (n > 0) {
            printf("factorielle_iterative(%2d) = %15d\n", n, factorielle_iterative(n));
            printf("factorielle_recursive(%2d) = %15d\n", n, factorielle_recursive(n));
        } else if (n == -1) {
            afficher_table_factorielles();
        }

    } while (n != 0);

    return 0;
}
