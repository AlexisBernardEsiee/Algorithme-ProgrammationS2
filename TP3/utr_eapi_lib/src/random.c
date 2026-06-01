/******************************************************************************
 * ESIEE Paris
 * Algorithmique et programmation pour l'ingénieur
 *
 * TP3 — Évaluation des performances du vecteur
 * Fichier : random.c
 *
 * Ce fichier contient l'implémentation des fonctions de génération de nombres
 * aléatoires pour différents types de données.
 *
 * Les fonctions sont volontairement laissées incomplètes afin d'être
 * implémentées par les étudiants.
 *
 ******************************************************************************/

/**
 * @file random.c
 * @brief TP3 - Génération de données aléatoires
 * @author ESIEE Paris
 * @date 2026
 *
 * Règles de travail :
 * - compilation sans erreur avec les options fournies ;
 * - gestion des cas limites (bornes inversées, pointeurs NULL, etc.) ;
 * - commentaires attendus sur chaque fonction.
 */

#include "random.h"
#include <stdlib.h>   // srand, rand
#include <time.h>     // time

/* ========================================================================== */
/* Initialisation du générateur aléatoire                                     */
/* ========================================================================== */

void random_init(uint32_t seed) {
    srand(seed);
}

/* ========================================================================== */
/* Génération de nombres aléatoires                                           */
/* ========================================================================== */

static double random_unit(void) {
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double a, double b) {
    if (a > b) {
        double tmp = a;
        a = b;
        b = tmp;
    }
    return a + random_unit() * (b - a);
}

float random_float(float a, float b) {
    float result = rand() / (RAND_MAX + 1.0f);
    result = a + result * (b - a);
    return result;
}

size_t random_size_t(size_t a, size_t b) {
<<<<<<< Updated upstream
    double tmp = random_double((double) a, (double) b);
    size_t result = (size_t) tmp;
    return result;
=======
    if (a > b) {
        size_t tmp = a;
        a = b;
        b = tmp;
    }
    if (a == b) {
        return a;
    }
    return a + (size_t)(random_unit() * (double)(b - a + 1));
>>>>>>> Stashed changes
}

int random_int(int a, int b) {
    const double tmp = random_double(a, b);
    const int result = (int) tmp;
    return result;
}

char random_char(char a, char b) {
    const double tmp = random_double(a, b);
    const char result = (char) tmp;
    return result;
}

/* ========================================================================== */
/* Génération de chaînes de caractères                                        */
/* ========================================================================== */

void random_init_string(char *c, size_t n) {
    for (size_t i = 0; i < n; i++) {
        char current = random_char('A', 'Z');
        c[i] = current;
    }
    c[n] = '\0';

}

/******************************************************************************
 * End of file: random.c
 ******************************************************************************/
