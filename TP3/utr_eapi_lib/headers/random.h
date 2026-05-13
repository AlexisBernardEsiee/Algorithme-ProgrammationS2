/******************************************************************************
 * ESIEE Paris
 * Algorithmique et programmation pour l'ingénieur
 *
 * TP3 — Évaluation des performances du vecteur
 * Fichier : random.h
 *
 * Ce fichier définit l'interface publique d'une petite bibliothèque de
 * génération de nombres aléatoires pour différents types de données.
 *
 ******************************************************************************/

#ifndef EAPI_RANDOM_H
#define EAPI_RANDOM_H

#include <stddef.h>
#include <stdint.h>

/* ========================================================================== */
/* Initialisation du générateur aléatoire                                     */
/* ========================================================================== */

/**
 * Initialise le générateur aléatoire avec la graine spécifiée.
 *
 * Si cette fonction n'est pas appelée, l'implémentation utilisera une graine
 * par défaut.
 *
 * @param seed Valeur de graine utilisée pour initialiser le générateur.
 */
void random_init(uint32_t seed);

/* ========================================================================== */
/* Génération de nombres aléatoires                                           */
/* ========================================================================== */

/**
 * Génère un double aléatoire dans l'intervalle [a, b).
 *
 * Si a > b, les bornes sont échangées.
 *
 * @param a Borne inférieure incluse.
 * @param b Borne supérieure exclue.
 * @return Valeur aléatoire de type double.
 */
double random_double(double a, double b);

/**
 * Génère un float aléatoire dans l'intervalle [a, b).
 *
 * Si a > b, les bornes sont échangées.
 *
 * @param a Borne inférieure incluse.
 * @param b Borne supérieure exclue.
 * @return Valeur aléatoire de type float.
 */
float random_float(float a, float b);

/**
 * Génère un size_t aléatoire dans l'intervalle [a, b].
 *
 * Si a > b, les bornes sont échangées.
 *
 * @param a Borne inférieure incluse.
 * @param b Borne supérieure incluse.
 * @return Valeur aléatoire de type size_t.
 */
size_t random_size_t(size_t a, size_t b);

/**
 * Génère un int aléatoire dans l'intervalle [a, b].
 *
 * Si a > b, les bornes sont échangées.
 *
 * @param a Borne inférieure incluse.
 * @param b Borne supérieure incluse.
 * @return Valeur aléatoire de type int.
 */
int random_int(int a, int b);

/**
 * Génère un char aléatoire dans l'intervalle [a, b].
 *
 * Si a > b, les bornes sont échangées.
 *
 * @param a Borne inférieure incluse.
 * @param b Borne supérieure incluse.
 * @return Valeur aléatoire de type char.
 */
char random_char(char a, char b);

/* ========================================================================== */
/* Génération de chaînes de caractères                                        */
/* ========================================================================== */

/**
 * Remplit une chaîne avec des lettres majuscules aléatoires entre 'A' et 'Z'.
 *
 * La fonction écrit n - 1 caractères, puis ajoute le caractère de fin de
 * chaîne '\0'.
 *
 * @param c Pointeur vers la chaîne à remplir.
 * @param n Taille de la chaîne allouée. Elle doit être supérieure ou égale à 1.
 */
void random_init_string(char *c, size_t n);

#endif /* EAPI_RANDOM_H */

/******************************************************************************
 * End of file: random.h
 ******************************************************************************/
