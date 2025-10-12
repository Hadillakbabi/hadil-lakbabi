#include "fib.h"

// --- Fibonacci using a naive method ---
int fibonacci_naive(int n) {
    if (n == 0 || n == 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// --- Fibonacci using dynamic programming ---
int fibonacci_dynamic(int n, int DP[]) {
    if (n == 0 || n == 1)
        return n;

    if (DP[n] != -1)
        return DP[n];

    DP[n] = fibonacci_dynamic(n - 1, DP) + fibonacci_dynamic(n - 2, DP);
    return DP[n];
}