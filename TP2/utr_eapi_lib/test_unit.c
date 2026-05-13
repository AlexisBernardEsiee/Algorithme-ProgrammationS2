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
 #include "vector.h"
 
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
     for(size_t i = 0; i < vec->size; i++) {
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
     
 // Fonction principale exécutant les tests
 int main() {
     int failed = 0;
 
     printf("[INFO] Lancement de la campagne de tests...\n");
 
     failed += test_vector_alloc_free();
     failed += test_vector_set_get();
     failed += test_vector_insert_erase();
     failed += test_vector_empty();
 
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