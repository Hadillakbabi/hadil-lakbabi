#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void) {
    int n = 10000; // taille du tableau
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Erreur d'allocation\n");
        return 1;
    }

    srand(time(NULL));

    // Remplir le tableau avec des nombres aléatoires
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    int *tmp = malloc(n * sizeof(int));
    if (!tmp) {
        free(arr);
        fprintf(stderr, "Erreur d'allocation\n");
        return 1;
    }

    clock_t start, end;
    double time_taken;

    // ===== Selection Sort =====
    copy_array(arr, tmp, n);
    start = clock();
    selection_sort(tmp, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.6f s\n", time_taken);

    // ===== Insertion Sort =====
    copy_array(arr, tmp, n);
    start = clock();
    insertion_sort(tmp, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %.6f s\n", time_taken);

    // ===== Bubble Sort =====
    copy_array(arr, tmp, n);
    start = clock();
    bubble_sort(tmp, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.6f s\n", time_taken);

    // ===== Merge Sort =====
    copy_array(arr, tmp, n);
    start = clock();
    merge_sort(tmp, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %.6f s\n", time_taken);

    // ===== Quick Sort =====
    copy_array(arr, tmp, n);
    start = clock();
    quick_sort(tmp, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %.6f s\n", time_taken);

    free(arr);
    free(tmp);

    return 0;
}
