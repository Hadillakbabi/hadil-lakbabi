#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int n = 1000000; 
    int target = 987654; 
    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        return 1;
    }

    // Remplir le tableau avec des valeurs triees
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    clock_t start, end;
    double time_taken;
    int index;

    // Linear Search 
    start = clock();
    index = linear_search(arr, n, target);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linear Search: index=%d, temps=%f secondes\n", index, time_taken);

    // Jump Search
    start = clock();
    index = jump_search(arr, n, target);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Jump Search: index=%d, temps=%f secondes\n", index, time_taken);

    // Binary Search
    start = clock();
    index = binary_search(arr, n, target);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search: index=%d, temps=%f secondes\n", index, time_taken);

    // Liberation de la memoire
    free(arr);

    return 0;
}
