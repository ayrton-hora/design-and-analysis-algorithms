#include <stdio.h>
#include <math.h>

void merge(int * B, int p, int * C, int q, int * A, int a);
void mergesort(int * A, int n);

int main() {
    int A[6] = {9, 3, 1, 6, 8, 5};
    int arraySize = sizeof(A) / sizeof(A[0]);

    printf("Orderable Array: \n[");
    for (int i = 0; i < arraySize - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[arraySize - 1]);

    mergesort(A, arraySize);

    printf("\nArray sorted in nondecreasing order by Merge Sort:\n[");
    for (int i = 0; i < arraySize - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[arraySize - 1]);

    return 0;
}

void merge(int * B, int p, int * C, int q, int * A, int a) {
    int i = 0; int j = 0; int k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        }
        else {
            A[k] = C[j];
            j++;
        }

        k++;
    }

    // printf("\nA:\n[");
    // for (int i = 0; i < a - 1; i++) {
    //     printf("%d, ", A[i]);
    // }
    // printf("%d]\n", A[a - 1]);

    printf("i: %d ", i);
    printf("p: %d\n", p);
    if (i == p) {
        while (j < q) {
            A[k] = C[j];
            k++; j++;
        }
    }
    else {
        while (i < p) {
            A[k] = B[i];
            k++; i++;
        }
    }

    // printf("\nA:\n[");
    // for (int i = 0; i < a - 1; i++) {
    //     printf("%d, ", A[i]);
    // }
    // printf("%d]\n", A[a - 1]);
    // printf("Merge OUT\n");
}

void mergesort(int * A, int n) {
    if (n > 1) {
        int middleDown = floor(n / 2);
        int middleUpper = ceil(n / 2);

        printf("floor: %d ", middleDown);
        printf("ceil: %d\n", middleUpper);
        
        int i = 0;
        int j = middleDown;

        int B[middleDown];
        while (i < middleDown) {
            B[i] = A[i];
            i++;
        }
        
        printf("\nB:\n[");
        for (int i = 0; i < middleDown - 1; i++) {
            printf("%d, ", B[i]);
        }
        printf("%d]\n", B[middleDown - 1]);

        i = 0; 
        int C[middleUpper];
        while (i < middleUpper) {
            C[i] = A[j];
            i++; j++;
        }

        printf("\nC:\n[");
        for (int i = 0; i < middleUpper - 1; i++) {
            printf("%d, ", C[i]);
        }
        printf("%d]\n", C[middleUpper - 1]);

        mergesort(B, middleDown);
        mergesort(C, middleUpper);
        merge(B, middleDown, C, middleUpper, A, n);
    }
}