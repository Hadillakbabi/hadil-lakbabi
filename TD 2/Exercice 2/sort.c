#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n){
    // selection sort iterative
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        swap_int(&arr[i],&arr[min]);
    }
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key
    }
}

void bubble_sort(int *arr, int n){
    void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j],&arr[j+1]);
            }
        }
    }
}


void merge(int *arr, int *tmp, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];

    for (int x = l; x <= r; x++)
        arr[x] = tmp[x];
}

void mergesort_rec(int *arr, int *tmp, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergesort_rec(arr, tmp, l, mid);
    mergesort_rec(arr, tmp, mid + 1, r);
    merge(arr, tmp, l, mid, r);
}

void merge_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    int *tmp = malloc(n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r) {
    int pivot = arr[r]; // pivot = dernier élément
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

void quick_sort_rec(int *arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quick_sort_rec(arr, l, pi - 1);
        quick_sort_rec(arr, pi + 1, r);
    }
}

void quick_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}
