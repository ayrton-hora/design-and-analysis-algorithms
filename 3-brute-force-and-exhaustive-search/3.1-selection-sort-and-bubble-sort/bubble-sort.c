#include <stdio.h>

void bubbleSort(int * A, int length);

int main() {
    int A[10] = {0, 3, 1, 6, 8, 5, 10, 9, 3, 4};
    int arraySize = sizeof(A) / sizeof(A[0]);

    bubbleSort(A, arraySize);

    printf("Sorted array in nondecreasing order by Bubble Sort: [");
    for (int i = 0; i < arraySize - 2; i++)
        printf("%d, ", A[i]);

    printf("%d]\n", A[arraySize - 1]);

    return 0;
}

void bubbleSort(int * A, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (A[j + 1] < A[j]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }   
}
