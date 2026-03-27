#include <stdio.h>

/*
 * TODO
 * Ecrire une fonction recursive qui calcule la longueur
 * d'une chaine de caracteres terminee par '\0'.
 */
int chaine_longueur_rec(char* s) {
    if (*s == '\0') {
        return 0;
    }
    return 1 + chaine_longueur_rec(s + 1);
}

/*
 * TODO
 * Ecrire une fonction recursive qui retourne un entier non nul
 * si s1 commence par s2, et 0 sinon.
 */
int chaine_commence_par(char* s1, char* s2) {
    if (*s2 == '\0') {
        return 1;
    }
    if (*s1 != *s2) {
        return 0;
    }
    return chaine_commence_par(s1 + 1, s2 + 1);
}

/*
 * TODO
 * Ecrire une fonction recursive qui retourne la position de s2 dans s1
 * si s1 contient s2, et -1 sinon.
 */
int chaine_index(char* s1, char* s2) {
    if (chaine_longueur_rec(s1) < chaine_longueur_rec(s2)) {
        return -1;
    }
    if (chaine_commence_par(s1, s2)) {
        return 0;
    }
    int res = chaine_index(s1 + 1, s2);
    return (res == -1) ? -1 : 1 + res;
}

void test_chaine_longueur_rec(void) {
    char s1[] = "bonjour";
    char s2[] = "";
    char s3[] = "abc";

    printf("=== Tests chaine_longueur_rec ===\n");
    printf("chaine_longueur_rec(\"%s\") = %d\n", s1, chaine_longueur_rec(s1));
    printf("chaine_longueur_rec(\"%s\") = %d\n", s2, chaine_longueur_rec(s2));
    printf("chaine_longueur_rec(\"%s\") = %d\n", s3, chaine_longueur_rec(s3));
    printf("\n");
}

void test_chaine_commence_par(void) {
    char s1[] = "bonjour";
    char s2[] = "bon";
    char s3[] = "bonjour";
    char s4[] = "jour";
    char s5[] = "";

    printf("=== Tests chaine_commence_par ===\n");
    printf("chaine_commence_par(\"%s\", \"%s\") = %d\n", s1, s2, chaine_commence_par(s1, s2));
    printf("chaine_commence_par(\"%s\", \"%s\") = %d\n", s1, s3, chaine_commence_par(s1, s3));
    printf("chaine_commence_par(\"%s\", \"%s\") = %d\n", s1, s4, chaine_commence_par(s1, s4));
    printf("chaine_commence_par(\"%s\", \"%s\") = %d\n", s1, s5, chaine_commence_par(s1, s5));
    printf("\n");
}

void test_chaine_index(void) {
    char s1[] = "bonjour";
    char s2[] = "bon";
    char s3[] = "jour";
    char s4[] = "o";
    char s5[] = "xyz";
    char s6[] = "";

    printf("=== Tests chaine_index ===\n");
    printf("chaine_index(\"%s\", \"%s\") = %d\n", s1, s2, chaine_index(s1, s2));
    printf("chaine_index(\"%s\", \"%s\") = %d\n", s1, s3, chaine_index(s1, s3));
    printf("chaine_index(\"%s\", \"%s\") = %d\n", s1, s4, chaine_index(s1, s4));
    printf("chaine_index(\"%s\", \"%s\") = %d\n", s1, s5, chaine_index(s1, s5));
    printf("chaine_index(\"%s\", \"%s\") = %d\n", s1, s6, chaine_index(s1, s6));
    printf("\n");
}

int main(void) {
    test_chaine_longueur_rec();
    test_chaine_commence_par();
    test_chaine_index();
    return 0;
}