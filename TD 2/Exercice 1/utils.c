#include "utils.h"

// return true if array is sorted and false otherwise
bool is_sorted_nondecreasing(int *arr, int n) {
    if (n <= 1) { 
        return true;
    }

    for (int i = 0; i < n - 1; i++) { 
        if (arr[i] > arr[i + 1]) { 
            return false;
        }
    }

    return true;
}

// return smallest value between a and b
int min_int(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
