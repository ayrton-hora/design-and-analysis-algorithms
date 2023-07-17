#include <stdio.h>

void insertionSort(int * A, int n);

int main() {
    int A[6] = {0, 3, 1, 6, 8, 5};
    int arraySize = sizeof(A) / sizeof(A[0]);

    printf("Orderable Array: \n[");
    for (int i = 0; i < arraySize - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[arraySize - 1]);

    insertionSort(A, arraySize);

    printf("Array sorted in nondecreasing order by Insertion Sort:\n[");
    for (int i = 0; i < arraySize - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[arraySize - 1]);

    return 0;
}

void insertionSort(int * A, int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}