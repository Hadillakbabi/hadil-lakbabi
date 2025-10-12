#include "prime.h"
#include <math.h>
#include <stdbool.h>

// Vérifie si un nombre est premier (version simple)
bool is_prime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Version naïve : compte les nombres premiers ≤ n
int prime_numbers_naive(int n) {
    int cpt = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i))
            cpt++;
    }
    return cpt;
}

// Version efficace : crible d'Ératosthène
int prime_numbers_efficient(int n) {
    if (n < 2) return 0;

    bool L[n + 1];
    for (int i = 0; i <= n; i++)
        L[i] = true;

    L[0] = L[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (L[i]) {
            for (int j = i * i; j <= n; j += i)
                L[j] = false;
        }
    }

    int cpt = 0;
    for (int i = 2; i <= n; i++) {
        if (L[i])
            cpt++;
    }
    return cpt;
}
