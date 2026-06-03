/******************************************************************************
 * ESIEE Paris
 * Algorithmique et programmation pour l'ingénieur
 *
 * TP2 — Tableau dynamique
 * Fichier : vector.h
 *
 * Ce fichier définit la structure et l'interface publique de la bibliothèque
 * de vecteurs dynamiques utilisée dans le TP.
 *
 ******************************************************************************/

 #ifndef EAPI_VECTOR_H
 #define EAPI_VECTOR_H
 
 #include <sys/types.h> // Pour size_t et ssize_t
 
 // Enumération pour le statut des fonctions
 typedef enum {
     VECTOR_SUCCESS = 0,
     VECTOR_ERROR_NULL_POINTER = -1,
     VECTOR_ERROR_ALLOCATION = -2,
     VECTOR_ERROR_OUT_OF_BOUNDS = -3,
     VECTOR_ERROR_NOT_EMPTY = -4
 } VectorStatus;
 
 // Structure du tableau dynamique
 struct struct_vector{
     size_t size;
#if defined(VERSION) && VERSION >= 3
     void* data;
     size_t element_size;
#else
     double* data;
#endif
#if defined(VERSION) && VERSION >= 2
     size_t capacity;
#endif
 };

 
 typedef struct struct_vector s_vector;
 typedef s_vector* p_s_vector;
 
 // Fonctions de manipulation du vecteur
#if defined(VERSION) && VERSION >= 3
p_s_vector vector_alloc(size_t n, void *data);
#else
p_s_vector vector_alloc(size_t n);
#endif
 VectorStatus vector_free(p_s_vector *p_vector);

#if defined(VERSION) && VERSION >= 3
 VectorStatus vector_set(p_s_vector p_vector, ssize_t i, void *v);
 VectorStatus vector_get(p_s_vector p_vector, ssize_t i, void **pv);
 
 VectorStatus vector_insert(p_s_vector p_vector, ssize_t i, void *v);
#else
VectorStatus vector_set(p_s_vector p_vector, ssize_t i, double v);
VectorStatus vector_get(p_s_vector p_vector, ssize_t i, double *pv);

VectorStatus vector_insert(p_s_vector p_vector, ssize_t i, double v);
#endif
VectorStatus vector_erase(p_s_vector p_vector, ssize_t i);

#if defined(VERSION) && VERSION >= 3
 VectorStatus vector_push_back(p_s_vector p_vector, void *v);
#else
 VectorStatus vector_push_back(p_s_vector p_vector, double v);
#endif
 VectorStatus vector_pop_back(p_s_vector p_vector);
 VectorStatus vector_clear(p_s_vector p_vector);
 
 VectorStatus vector_empty(p_s_vector p_vector);
 VectorStatus vector_size(p_s_vector p_vector, size_t *size);
 
 #endif /* EAPI_VECTOR_H */

/******************************************************************************
 * End of file: vector.h
 ******************************************************************************/
