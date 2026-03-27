#include <stdio.h>
#include <math.h>

/*
 * TODO
 * Écrire la fonction print_hexa(double x)
 * qui affiche :
 *   - la valeur de x
 *   - puis son codage hexadécimal sur 8 octets
 */
 void print_hexa(double x) {
    unsigned char *p = (unsigned char *)&x;

    printf("Valeur : %.17g\n", x);
    printf("Hexa   : ");

    for (int i = 0; i < 8; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n\n");
}
int main(void) {
    double x = 1.0;
    double y = x + 1e-100;
    double inf = 1.0 / 0.0;
    double nan_value = 0.0 / 0.0;

    printf("=== Valeur initiale ===\n");
    print_hexa(x);

    printf("=== Apres ajout d'une tres petite valeur ===\n");
    print_hexa(y);

    printf("=== inf ===\n");
    print_hexa(inf);

    printf("=== nan ===\n");
    print_hexa(nan_value);

    return 0;
}
