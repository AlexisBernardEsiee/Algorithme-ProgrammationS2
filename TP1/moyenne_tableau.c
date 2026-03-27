#include <stdio.h>
#include <math.h>

#define ABS_TOL 1e-9

/*
 * TODO
 * Recopier ici l'implémentation de proche_abs
 * écrite dans l'exercice précédent.
 */
int proche_abs(double a, double b, double eps) {
    if (fabs(a - b) <= eps) {
        return 1;
    }
    else {
        return 0;
    }
}

double moyenne(double t[], int n) {
/* calcule la moyenne des n premiers elements du tableau t */
/* --------------
 * a faire
 * --------------
*/
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += t[i];
    }
    return sum / n;
}

double moyenne_positifs(double t[]) {
/* calcule la moyenne des elements du tableau t jusqu'a rencontrer un
element negatif et retourne -1.0 si le premier element est deja negatif */
/* --------------
 * a faire
 * --------------
*/
    if(t[0] < 0) return -1.0;
    double sum = 0.0;
    int i = 0;
    for(; t[i] >= 0; i++){
        sum += t[i];
    }
    return (double) (sum/i);
}

void test_moyenne(void) {
    double v[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, -1.0};
    double d, attendu;

    attendu = 1.0;
/* test moyenne */
    if (!proche_abs((d = moyenne(v, 1)), attendu, ABS_TOL)) {
        printf("Pb moyenne. Attendu : %f Obtenu : %f\n", attendu, d);
    }

    attendu = 2.0;
    if (!proche_abs((d = moyenne(v, 3)), attendu, ABS_TOL)) {
        printf("Pb moyenne. Attendu : %f Obtenu : %f\n", attendu, d);
    }

    attendu = 3.5;
    if (!proche_abs((d = moyenne(v, 6)), attendu, ABS_TOL)) {
        printf("Pb moyenne. Attendu : %f Obtenu : %f\n", attendu, d);
    }
    printf("Test moyenne termines\n");

/* test moyenne_positifs */
    attendu = 3.5;
    if (!proche_abs((d = moyenne_positifs(v)), attendu, ABS_TOL)) {
        printf("Pb moyenne_positifs. Attendu : %f Obtenu : %f\n", attendu, d);
    }

    attendu = 5.0;
    if (!proche_abs((d = moyenne_positifs(v + 3)), attendu, ABS_TOL)) {
        printf("Pb moyenne_positifs. Attendu : %f Obtenu : %f\n", attendu, d);
    }

    attendu = -1.0;
    if (!proche_abs((d = moyenne_positifs(v + 6)), attendu, ABS_TOL)) {
        printf("Pb moyenne_positifs. Attendu : %f Obtenu : %f\n", attendu, d);
    }

    printf("Test moyenne_positifs termines\n");
}

int main(void) {
    test_moyenne();
    return 0;
}
