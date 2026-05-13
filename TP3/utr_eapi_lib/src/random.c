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
    // À implémenter
}

/* ========================================================================== */
/* Génération de nombres aléatoires                                           */
/* ========================================================================== */

double random_double(double a, double b) {
    // À implémenter
    return 0.0;
}

float random_float(float a, float b) {
    // À implémenter
    return 0.0f;
}

size_t random_size_t(size_t a, size_t b) {
    // À implémenter
    return 0;
}

int random_int(int a, int b) {
    // À implémenter
    return 0;
}

char random_char(char a, char b) {
    // À implémenter
    return 'A';
}

/* ========================================================================== */
/* Génération de chaînes de caractères                                        */
/* ========================================================================== */

void random_init_string(char *c, size_t n) {
    // À implémenter
}

/******************************************************************************
 * End of file: random.c
 ******************************************************************************/
