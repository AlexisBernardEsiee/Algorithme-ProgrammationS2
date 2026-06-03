/******************************************************************************
 * ESIEE Paris
 * Algorithmique et programmation pour l'ingénieur
 *
 * TP2 — Tests unitaires de la bibliothèque vector
 * Fichier : test_unit.c
 *
 * Ce programme contient une série de tests permettant de vérifier le bon
 * fonctionnement des fonctions implémentées dans vector.c.
 *
 * Les étudiants peuvent compléter ou enrichir ces tests.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/vector.h"
#include "../headers/random.h"

// Macro pour les tests unitaires
#define ASSERT(condition) do { \
     if (!(condition)) { \
         fprintf(stderr, "Assertion échouée dans %s:%d: %s\n", __FILE__, __LINE__, #condition); \
         return 1; \
     } \
 } while (0)

// Test d'allocation et de libération de mémoire
int test_vector_alloc_free() {
    p_s_vector vec = vector_alloc(5);
    ASSERT(vec != NULL);
    ASSERT(vec->size == 5);
    ASSERT(vec->data != NULL);
    for (size_t i = 0; i < vec->size; i++) {
        ASSERT(vec->data[i] == 0.0); // Vérifie que les éléments sont initialisés à 0
    }

    ASSERT(vector_free(&vec) == VECTOR_SUCCESS);
    ASSERT(vec == NULL); // Vérifie que le pointeur est mis à NULL après libération

    return 0;
}

// Test d'insertion et de récupération d'éléments (à compléter par les étudiants)
int test_vector_set_get() {
    p_s_vector vec = vector_alloc(5);
    vector_set(vec, 3, 1.3);
    ASSERT(vec->data[3] == 1.3);
    double v;
    vector_get(vec, 3, &v);
    ASSERT(v == 1.3);
    return 0;
}

int test_vector_insert_erase() {
    p_s_vector vec = vector_alloc(1);
    ASSERT(vec != NULL);

    ASSERT(vector_set(vec, 0, 1.0) == VECTOR_SUCCESS);
    ASSERT(vector_insert(vec, 1, 2.0) == VECTOR_SUCCESS);
    ASSERT(vector_push_back(vec, 3.0) == VECTOR_SUCCESS);

    double value = 0.0;
    ASSERT(vector_get(vec, 2, &value) == VECTOR_SUCCESS);
    ASSERT(value == 3.0);

    ASSERT(vector_erase(vec, 1) == VECTOR_SUCCESS);
    ASSERT(vector_pop_back(vec) == VECTOR_SUCCESS);
    ASSERT(vec->size == 1);

    return 0;
}

// Test de la fonction vector_empty() (à compléter par les étudiants)
int test_vector_empty() {
    p_s_vector vec = vector_alloc(0);
    ASSERT(vec != NULL);

    ASSERT(vector_empty(vec) == VECTOR_SUCCESS);

    ASSERT(vector_push_back(vec, 1.0) == VECTOR_SUCCESS);
    ASSERT(vector_empty(vec) == VECTOR_ERROR_NOT_EMPTY);

    ASSERT(vector_clear(vec) == VECTOR_SUCCESS);
    ASSERT(vector_empty(vec) == VECTOR_SUCCESS);

    size_t size = 42;
    ASSERT(vector_size(vec, &size) == VECTOR_SUCCESS);
    ASSERT(size == 0);

    ASSERT(vector_free(&vec) == VECTOR_SUCCESS);

    return 0;
}

int test_random_double() {
    random_init(time(NULL));
    double a = 1.5;
    double b = 2.3;
    double result = random_double(a, b);

    ASSERT(a <= result);
    ASSERT(b >= result);
    double result2 = random_double(a, b);
    ASSERT(result != result2);
    ASSERT(a <= result2);
    ASSERT(b >= result2);

    double result3 = random_double(b, a);
    ASSERT(result != result3);
    ASSERT(a <= result3);
    ASSERT(b >= result3);

    double result4 = random_double(a, a);
    ASSERT(a == result4);
    return 0;
}

int test_random_float() {
    random_init(time(NULL));
    float a = 1.5;
    float b = 2.3;
    float result = random_float(a, b);

    ASSERT(a <= result);
    ASSERT(b >= result);
    float result2 = random_float(a, b);
    ASSERT(result != result2);
    ASSERT(a <= result2);
    ASSERT(b >= result2);

    float result3 = random_float(b, a);
    ASSERT(result != result3);
    ASSERT(a <= result3);
    ASSERT(b >= result3);

    float result4 = random_float(a, a);
    ASSERT(a == result4);
    return 0;
}

int test_random_size_t() {
    random_init(time(NULL));
    size_t a = 0;
    size_t b = 100;
    size_t result = random_size_t(a, b);

    ASSERT(a <= result);
    ASSERT(b >= result);
    size_t result2 = random_size_t(a, b);
    ASSERT(result != result2);
    ASSERT(a <= result2);
    ASSERT(b >= result2);

    size_t result3 = random_size_t(b, a);
    ASSERT(result != result3);
    ASSERT(a <= result3);
    ASSERT(b >= result3);

    size_t result4 = random_size_t(a, a);
    ASSERT(a == result4);
    return 0;
}

int test_random_int() {
    random_init(time(NULL));
    int a = 0;
    int b = 100;
    int result = random_int(a, b);

    ASSERT(a <= result);
    ASSERT(b >= result);
    int result2 = random_int(a, b);
    ASSERT(result != result2);
    ASSERT(a <= result2);
    ASSERT(b >= result2);

    int result3 = random_int(b, a);
    ASSERT(result != result3);
    ASSERT(a <= result3);
    ASSERT(b >= result3);

    int result4 = random_int(a, a);
    ASSERT(a == result4);
    return 0;
}

int test_random_char() {
    random_init(time(NULL));
    char a = 0;
    char b = 100;
    char result = random_char(a, b);

    ASSERT(a <= result);
    ASSERT(b >= result);
    char result2 = random_char(a, b);
    ASSERT(result != result2);
    ASSERT(a <= result2);
    ASSERT(b >= result2);

    char result3 = random_char(b, a);
    ASSERT(result != result3);
    ASSERT(a <= result3);
    ASSERT(b >= result3);

    char result4 = random_char(a, a);
    ASSERT(a == result4);
    return 0;
}

int test_random_init_string() {
    size_t n = 30;
    random_init(time(NULL));
    char c[n];
    random_init_string(c, n);
    for (size_t i = 0; i < n; i++) {
        ASSERT(c[i] >= 'A' && c[i] <= 'Z');
    }
    return 0;
}

// Fonction principale exécutant les tests
int main() {
    int failed = 0;

    printf("[INFO] Lancement de la campagne de tests...\n");

    failed += test_vector_alloc_free();
    failed += test_vector_set_get();
    failed += test_vector_insert_erase();
    failed += test_vector_empty();
    failed += test_random_double();
    failed += test_random_float();
    failed += test_random_size_t();
    failed += test_random_int();
    failed += test_random_char();
    failed += test_random_init_string();

    if (failed == 0) {
        printf("[OK] Tous les tests sont validés.\n");
    } else {
        printf("[ERREUR] Échecs détectés dans %d test(s). \n", failed);
    }

    return failed;
}

/******************************************************************************
 * End of file: test_unit.c
 ******************************************************************************/
