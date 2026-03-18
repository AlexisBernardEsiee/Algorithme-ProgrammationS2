#include <stdio.h>
#include <math.h>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

/*
 * TODO
 * Retourner un entier non nul si a == b, 0 sinon.
 */
int equal(double a, double b) {
    if (a == b) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * TODO
 * Retourner un entier non nul si |a-b| <= eps, 0 sinon.
 */
int proche_abs(double a, double b, double eps) {
    if (fabs(a - b) <= eps) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * TODO
 * Retourner un entier non nul si
 * |a-b| <= eps * max(|a|, |b|), 0 sinon.
 */
int proche_rel(double a, double b, double eps) {
    if (fabs(a - b) <= eps * MAX(fabs(a), fabs(b))) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * TODO
 * Retourner un entier non nul si
 * |a-b| <= max(rel_tol * max(|a|, |b|), abs_tol), 0 sinon.
 */
int proche_pep_0485(double a, double b, double rel_tol, double abs_tol) {
    if (fabs(a - b) <= MAX(rel_tol * MAX(fabs(a), fabs(b)), abs_tol)) {
        return 1;
    }
    else {
        return 0;
    }
}

void test_case(double a, double b, double eps_abs, double eps_rel,
               double rel_tol, double abs_tol) {
    printf("a = %.17g, b = %.17g\n", a, b);
    printf("  equal                : %d\n", equal(a, b));
    printf("  proche_abs           : %d (eps = %.17g)\n", proche_abs(a, b, eps_abs), eps_abs);
    printf("  proche_rel           : %d (eps = %.17g)\n", proche_rel(a, b, eps_rel), eps_rel);
    printf("  proche_pep_0485      : %d (rel_tol = %.17g, abs_tol = %.17g)\n",
           proche_pep_0485(a, b, rel_tol, abs_tol), rel_tol, abs_tol);
    printf("\n");
}

int main(void) {
    printf("=== Cas 1 : meme valeur mathematique, calcul flottant different ===\n");
    test_case(0.1 + 0.2, 0.3, 1e-12, 1e-12, 1e-9, 0.0);

    printf("=== Cas 2 : valeurs proches autour de 1 ===\n");
    test_case(1.0, 1.0 + 1e-10, 1e-12, 1e-9, 1e-9, 0.0);

    printf("=== Cas 3 : valeurs proches mais tres grandes ===\n");
    test_case(1e12, 1e12 + 1.0, 1e-9, 1e-9, 1e-9, 0.0);

    printf("=== Cas 4 : valeurs tres proches de zero ===\n");
    test_case(1e-12, 2e-12, 1e-12, 1e-9, 1e-9, 0.0);

    printf("=== Cas 5 : proche de zero avec tolerance absolue utile ===\n");
    test_case(1e-12, 2e-12, 1e-12, 1e-9, 1e-9, 1e-12);

    printf("=== Cas 6 : zero et tres petite valeur ===\n");
    test_case(0.0, 1e-15, 1e-12, 1e-9, 1e-9, 0.0);

    printf("=== Cas 7 : zero et tres petite valeur avec abs_tol ===\n");
    test_case(0.0, 1e-15, 1e-12, 1e-9, 1e-9, 1e-12);

    printf("=== Cas 8 : influence de rel_tol ===\n");
    test_case(1000.0, 1000.1, 1e-3, 1e-6, 1e-6, 0.0);
    test_case(1000.0, 1000.1, 1e-3, 1e-4, 1e-4, 0.0);

    return 0;
}
