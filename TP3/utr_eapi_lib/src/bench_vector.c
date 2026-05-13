/******************************************************************************
 * ESIEE Paris
 * Algorithmique et programmation pour l'ingénieur
 *
 * TP3 — Évaluation des performances du vecteur
 * Fichier : bench_vector.c
 *
 * Ce programme permet de lancer différents scénarios de test afin d'évaluer
 * les performances de la bibliothèque vector.
 *
 * Les fonctions de benchmark sont volontairement laissées incomplètes afin
 * d'être implémentées par les étudiants.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "random.h"
#include "vector.h"

/* ========================================================================== */
/* Benchmarks : insertions et suppressions                                    */
/* ========================================================================== */

void insert_erase_random(size_t init_size, size_t n) {
    printf("Test: insert_erase_random, init_size=%zu, ops=%zu\n", init_size, n);
    // À implémenter
}

void insert_erase_head(size_t init_size, size_t n) {
    printf("Test: insert_erase_head, init_size=%zu, ops=%zu\n", init_size, n);
    // À implémenter
}

void insert_erase_tail(size_t init_size, size_t n) {
    printf("Test: insert_erase_tail, init_size=%zu, ops=%zu\n", init_size, n);
    // À implémenter
}

/* ========================================================================== */
/* Benchmarks : lectures et écritures                                         */
/* ========================================================================== */

void read_write_random(size_t init_size, size_t n) {
    printf("Test: read_write_random, init_size=%zu, ops=%zu\n", init_size, n);
    // À implémenter
}

void read_write_sequential(size_t init_size, size_t n) {
    printf("Test: read_write_sequential, init_size=%zu, ops=%zu\n", init_size, n);
    // À implémenter
}

/* ========================================================================== */
/* Benchmark : tri                                                            */
/* ========================================================================== */

void bubble_sort(size_t init_size, size_t n) {
    printf("Test: bubble_sort (repeated %zu times), size=%zu\n", n, init_size);
    // À implémenter
}

/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <test_type> <init_size> <n>\n", argv[0]);
        fprintf(stderr, "Where:\n");
        fprintf(stderr, "  <test_type> : insert_erase_random | insert_erase_head | "
                        "insert_erase_tail | read_write_random | "
                        "read_write_sequential | bubble_sort\n");
        fprintf(stderr, "  <init_size> : initial number of elements (size_t)\n");
        fprintf(stderr, "  <n>         : number of operations or repetitions (size_t)\n");
        fprintf(stderr, "Example: %s insert_erase_random 10000 1000000\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *test = argv[1];
    size_t init_size = strtoul(argv[2], NULL, 10);
    size_t n = strtoul(argv[3], NULL, 10);

    random_init((uint32_t)time(NULL));

    if (strcmp(test, "insert_erase_random") == 0) {
        insert_erase_random(init_size, n);
    } else if (strcmp(test, "insert_erase_head") == 0) {
        insert_erase_head(init_size, n);
    } else if (strcmp(test, "insert_erase_tail") == 0) {
        insert_erase_tail(init_size, n);
    } else if (strcmp(test, "read_write_random") == 0) {
        read_write_random(init_size, n);
    } else if (strcmp(test, "read_write_sequential") == 0) {
        read_write_sequential(init_size, n);
    } else if (strcmp(test, "bubble_sort") == 0) {
        bubble_sort(init_size, n);
    } else {
        fprintf(stderr, "Unknown test: %s\n", test);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/******************************************************************************
 * End of file: bench_vector.c
 ******************************************************************************/
