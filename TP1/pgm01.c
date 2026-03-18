/*
pgm01.c Un premier exemple de programme C
*/
#include <stdio.h>

int main(void) {
    int n;
    printf("Entrez un nombre entier : ");
    scanf("%d", &n);
    printf("%d x %d = %d\n", n, n, n * n);
    return 0;
}
