include "utils.h"

void swap_int(int *a, int *b){
    // swap two elements
    int c = *a;
    *a = *b;
    *b = c;
}


bool is_sorted_nondecreasing(int *arr, int n){
    // check if array is sorted, if yes return true
    // if not return false
    for (int i=0; i<n; i++){
        if (arr[i+1]<arr[i]){
            return false;
        }
        else{
            return true;
        }
    }
}

void copy_array(int *src, int *dst, int n){
    // copy array elements src into dst
    for (int i=0; i<n+1; i++){
        dst[i]=src[i];
    }
}