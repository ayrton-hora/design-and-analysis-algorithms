#include <stdio.h>

void selectionSort(int * A, int lenght);

int main() {
    int A[6] = {0, 3, 1, 6, 8, 5};
    int arraySize = sizeof(A) / sizeof(A[0]);

    selectionSort(A, arraySize);

    printf("Sorted array in nondecreasing order by Selection Sort: [");
    for (int i = 0; i < 5; i++)
        printf("%d, ", A[i]);

    printf("%d]\n", A[5]);

    return 0;
}

void selectionSort(int * A, int lenght) {
    int min, temp;
    for (int i = 0; i < lenght - 1; i++) {
        min = i;
        for (int j = i + 1; j < lenght; j++) {
            if (A[j] < A[min])
                min = j;
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}
