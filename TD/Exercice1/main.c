#include <stdio.h>
#include <time.h>
#include "fib.h"


// --- Main function ---
int main() {
    int n;

    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    int DP[n + 1];
    for (int i = 0; i <= n; i++)
        DP[i] = -1;

    // --- Mesuring time for the first method ---
    clock_t start1 = clock();
    int result1 = fibonacci_naive(n);
    clock_t end1 = clock();

    // --- Mesuring time for the second method ---
    clock_t start2 = clock();
    int result2 = fibonacci_dynamic(n, DP);
    clock_t end2 = clock();

    // --- Time calculations ---
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    // --- Affichage des résultats ---
    printf("\nFibonacci(%d) = %d\n", n, result1);
    printf("Temps version naïve    : %.6f secondes\n", time1);
    printf("Temps version dynamique : %.6f secondes\n", time2);

    if (time1 < time2)
        printf("La version naïve est plus rapide.\n");
    else if (time2 < time1)
        printf("La version dynamique est plus rapide.\n");
    else
        printf("Les deux versions ont le même temps.\n");

    return 0;
}
