#include "sort.h"

void insertion_sort(int* A, int n) {
    int j;

    for (j = 1; j < n; j++) {
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void insertion_down_sort(int* A, int n) {
    int j;

    for (j = 1; j < n; j++) {
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

static void merge(int* A, int left, int mid, int right) {
    int length = right - left + 1;
    int temp[length];
    int i = left, j = mid + 1, k;

    for (k = 0; i <= mid && j <= right; k++) {
        temp[k] = A[i] <= A[j] ? A[i++] : A[j++];
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }
    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (k = 0; k < length; k++) {
        A[left + k] = temp[k];
    }
}

void merge_sort(int* A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

static int partition(int* A, int left, int right) {
    int key = A[left];

    while (left < right) {
        while (left < right && A[right] >= key)
            right--;
        
        if (left < right)
            A[left++] = A[right];
        
        while (left < right && A[left] <= key)
            left++;
        
        if (left < right)
            A[right--] = A[left];
    }
    A[left] = key;

    return left;
}

void quick_sort(int* A, int left, int right) {
    if (left < right) {
        int pos = partition(A, left, right);
        quick_sort(A, left, pos - 1);
        quick_sort(A, pos + 1, right);
    }
}