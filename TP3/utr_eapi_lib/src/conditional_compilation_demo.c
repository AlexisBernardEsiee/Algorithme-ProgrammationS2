/******************************************************************************
 * ESIEE Paris
 * Algorithmique et programmation pour l'ingénieur
 *
 * TP3 — Évaluation des performances du vecteur
 * Fichier : conditional_compilation_demo.c
 *
 * Ce programme illustre l'utilisation de la compilation conditionnelle en C
 * à l'aide des directives du préprocesseur (#ifdef, #ifndef, #elif, etc.).
 *
 * Le comportement du programme dépend de la constante VERSION définie lors
 * de la compilation (via les options du compilateur).
 *
 ******************************************************************************/

/**
 * @file conditional_compilation_demo.c
 * @brief TP3 - Démonstration de la compilation conditionnelle
 * @author ESIEE Paris
 * @date 2026
 *
 * Règles de travail :
 * - comprendre le rôle du préprocesseur ;
 * - expérimenter avec différentes valeurs de VERSION ;
 * - observer l'impact sur le code compilé.
 */

#include <stdio.h>

/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */

int main(int argc, char *argv[]) {

    /*
     * Si VERSION n'est pas définie :
     * -> version par défaut
     */
#ifndef VERSION
    printf("Version par defaut.\n");

    /*
     * Si VERSION == 2 :
     * -> version 2
     */
#elif VERSION == 2
    printf("Version 2.0 du code.\n");

    /*
     * Si VERSION == 3 :
     * -> version 3
     */
#elif VERSION == 3
    printf("Version 3.0 du code.\n");

    /*
     * Cas théoriquement impossible si les versions sont contrôlées
     */
#else
    printf("Impossible d'arriver ici normalement !\n");
#endif

    return 0;
}

/******************************************************************************
 * End of file: conditional_compilation_demo.c
 ******************************************************************************/
