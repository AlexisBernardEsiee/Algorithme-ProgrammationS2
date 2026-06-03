/**
 * @file vector.c
 * @brief TP2 - Bibliothèque de tableau dynamique
 * @author ESIEE Paris
 * @date 2026
 *
 * Règles de travail :
 * - compilation sans erreur avec les options fournies ;
 * - gestion systématique des erreurs ;
 * - commentaires attendus sur chaque fonction.
 */

 #include "vector.h"
 #include <stdlib.h> // Pour malloc, free, realloc

#if defined(VERSION) && VERSION >= 2

#define VECTOR_MIN_CAPACITY 16

static size_t vector_initial_capacity(size_t n) {
    size_t p = VECTOR_MIN_CAPACITY;
    while (p < n) {
        p *= 2;
    }
    return p;
}

static VectorStatus update_capacity(p_s_vector v) {
    if (v == NULL) {
        return VECTOR_ERROR_NULL_POINTER;
    }

    if (v->size == v->capacity) {
        size_t new_capacity = v->capacity * 2;
        double *new_data = realloc(v->data, new_capacity * sizeof(double));
        if (new_data == NULL) {
            return VECTOR_ERROR_ALLOCATION;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    while (v->size <= v->capacity / 4 && v->capacity > VECTOR_MIN_CAPACITY) {
        size_t new_capacity = v->capacity / 2;
        double *new_data = realloc(v->data, new_capacity * sizeof(double));
        if (new_data == NULL) {
            return VECTOR_ERROR_ALLOCATION;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    return VECTOR_SUCCESS;
}

#endif

 /* ========================================================================== */
 /* Allocation / libération                                                    */
 /* ========================================================================== */
 
 // Alloue et initialise un tableau dynamique
 p_s_vector vector_alloc(size_t n) {
     p_s_vector vector = malloc(sizeof(s_vector));
     if(vector == NULL) {
        return NULL;
     }
     vector->size = n;
#if defined(VERSION) && VERSION >= 2
     vector->capacity = vector_initial_capacity(n);
     vector->data = malloc(vector->capacity * sizeof(double));
     if (vector->data == NULL) {
         free(vector);
         return NULL;
     }
     for (size_t i = 0; i < n; i++) {
         vector->data[i] = 0.0;
     }
#else
     vector->data = calloc(n, sizeof(double));
     if(vector->data == NULL) {
         free(vector);
        return NULL;
     }
#endif
     return vector;
 }
 
 // Libère la mémoire du tableau dynamique et met le pointeur à NULL
VectorStatus vector_free(p_s_vector *p_vector) {
   if(p_vector == NULL || *p_vector == NULL)
     {
         return VECTOR_ERROR_NULL_POINTER;
     }
 
   free((*p_vector)->data);
   free(*p_vector);
   *p_vector = NULL;
     return VECTOR_SUCCESS;
 }
 
 /* ========================================================================== */
 /* Accès aux données                                                          */
 /* ========================================================================== */
 
 // Affecte la valeur v à l'index i du tableau dynamique
 VectorStatus vector_set(p_s_vector p_vector, ssize_t i, double v) {
     if(p_vector == NULL) 
     {
         return VECTOR_ERROR_NULL_POINTER;
     }   
    if(i < 0 || (size_t)i >= p_vector->size)
     {
         return VECTOR_ERROR_OUT_OF_BOUNDS;
     }
 
     p_vector->data[i] = v;
     return VECTOR_SUCCESS;
 }
 
 // Récupère la valeur stockée à l'index i et la stocke dans pv
VectorStatus vector_get(p_s_vector p_vector, ssize_t i, double *pv) {
     if(p_vector == NULL || pv == NULL)
     {
         return VECTOR_ERROR_NULL_POINTER;
     }
 
    if(i < 0 || (size_t)i >= p_vector->size){
         return VECTOR_ERROR_OUT_OF_BOUNDS;
     }
     *pv = p_vector->data[i];
     return VECTOR_SUCCESS;
 }
 
 
 /* ========================================================================== */
 /* Modifications de structure                                                 */
 /* ========================================================================== */
 
 // Insère une nouvelle valeur v à l'index i du tableau dynamique
 VectorStatus vector_insert(p_s_vector p_vector, ssize_t i, double v) {
     if (p_vector == NULL) 
     {
         return VECTOR_ERROR_NULL_POINTER;
     }
     if (i < 0 || (size_t)i > p_vector->size) 
     {
         return VECTOR_ERROR_OUT_OF_BOUNDS;
     }

#if defined(VERSION) && VERSION >= 2
     VectorStatus status = update_capacity(p_vector);
     if (status != VECTOR_SUCCESS) {
         return status;
     }
#else
     double *new_data = realloc(p_vector->data, (p_vector->size + 1) * sizeof(double));

     if (new_data == NULL) 
     {
         return VECTOR_ERROR_ALLOCATION;
     }

     p_vector->data = new_data;
#endif
 
     for (size_t j = p_vector->size; j > (size_t)i; j--) 
     {
         p_vector->data[j] = p_vector->data[j - 1];
     }
     p_vector->data[i] = v;
     p_vector->size++;
     return VECTOR_SUCCESS;
 }
 
 // Supprime la valeur située à l'index i du tableau dynamique
 VectorStatus vector_erase(p_s_vector p_vector, ssize_t i) {
     if(p_vector == NULL)
     {
         return VECTOR_ERROR_NULL_POINTER;
     }
 
     if(i < 0)
     {
         return VECTOR_ERROR_OUT_OF_BOUNDS;
     }
    if((size_t)i >= p_vector->size)
     {
         return VECTOR_ERROR_OUT_OF_BOUNDS;
     }
 
     for(size_t j = i; j < p_vector->size - 1; j++) 
     {
         p_vector->data[j] = p_vector->data[j + 1];
     }
     p_vector->size--;

#if defined(VERSION) && VERSION >= 2
     return update_capacity(p_vector);
#else
     return VECTOR_SUCCESS;
#endif
 }
 
 // Ajoute une valeur à la fin du tableau dynamique
 VectorStatus vector_push_back(p_s_vector p_vector, double v) {
     if (p_vector == NULL)
     {
         return VECTOR_ERROR_NULL_POINTER;
     }

#if defined(VERSION) && VERSION >= 2
     VectorStatus status = update_capacity(p_vector);
     if (status != VECTOR_SUCCESS) {
         return status;
     }
#else
    double *new_data = realloc(p_vector->data, (p_vector->size + 1) * sizeof(double));
    if (new_data == NULL) 
     {
         return VECTOR_ERROR_ALLOCATION;
     }

    p_vector->data = new_data;
#endif

     p_vector->data[p_vector->size] = v;
     p_vector->size++;
     return VECTOR_SUCCESS;
 }
 
 // Supprime la dernière valeur du tableau dynamique
 VectorStatus vector_pop_back(p_s_vector p_vector) {
     if (p_vector == NULL) 
     {
         return VECTOR_ERROR_NULL_POINTER; 
    }
    if (p_vector->size == 0)
    {
         return VECTOR_ERROR_OUT_OF_BOUNDS;
     }

#if defined(VERSION) && VERSION >= 2
     p_vector->size--;
     return update_capacity(p_vector);
#else
    if (p_vector->size > 1) {
        double *new_data = realloc(p_vector->data, (p_vector->size - 1) * sizeof(double));
        if (new_data == NULL) {
            return VECTOR_ERROR_ALLOCATION;
        }
        p_vector->data = new_data;
    } else {
        free(p_vector->data);
        p_vector->data = NULL;
     }
     p_vector->size--;
     return VECTOR_SUCCESS;
#endif
 }
 
 // Supprime toutes les valeurs du tableau dynamique
 VectorStatus vector_clear(p_s_vector p_vector) {
     if (p_vector == NULL) 
     {
         return VECTOR_ERROR_NULL_POINTER;
     }

#if defined(VERSION) && VERSION >= 2
     p_vector->size = 0;
     return update_capacity(p_vector);
#else
     free(p_vector->data);
     p_vector->data = NULL;
     p_vector->size = 0;
#endif
     return VECTOR_SUCCESS;
 }
 
 // Vérifie si le tableau dynamique est vide
 VectorStatus vector_empty(p_s_vector p_vector) {
     if (p_vector == NULL) 
     {
         return VECTOR_ERROR_NULL_POINTER;
     }
 
     if (p_vector->size != 0) 
     {
         return VECTOR_ERROR_NOT_EMPTY;
     }
     return VECTOR_SUCCESS;
 }
 
 // Récupère le nombre d'éléments stockés dans le tableau dynamique
VectorStatus vector_size(p_s_vector p_vector, size_t *size) {
   if (p_vector == NULL || size == NULL) 
     {
         return VECTOR_ERROR_NULL_POINTER;
     }
   *size = p_vector->size;
    return VECTOR_SUCCESS;  
 }
 
 /* End of file: vector.c */
