#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * binaryReflectedGrayCode(int n, int subsetsTotal);

int main() {
    int n = 0;
    printf("Binary Reflected Gray Code Alghorithm to get all subsets in bit strings\n\n"); 
    while (n <= 0) {
        printf("Please insert a non-zero positive integer value: ");
        scanf("%d", &n);
    }
    printf("\n");

    binaryReflectedGrayCode(n, pow(2, n));

    return 0;
}

char * binaryReflectedGrayCode(int n, int subsetsTotal) {
    if (n == 1) return "01";

    else {
        char * l1 = binaryReflectedGrayCode(n - 1, subsetsTotal);

        char * l2 = l1;
        for (int i = 0; i < subsetsTotal; i++) l2[i] = l1[subsetsTotal - 1 - i];

        for (int i = 0; i < subsetsTotal - 1; i++) {
            for (int j = subsetsTotal - 1; j > i; j--) l1[j] = l1[j - 1];
            l1[i] = '0';
        }

        for (int i = 0; i < subsetsTotal - 1; i++) {
            for (int j = subsetsTotal - 1; j > i; j--) l2[j] = l2[j - 1];
            l2[i] = '1';
        }

        return NULL;
    }
}
