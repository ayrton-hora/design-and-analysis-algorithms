#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Element {
    int value;
    int pos;
} Element;

typedef struct ElementsPair {
    Element first;
    Element second;
} ElementsPair;


ElementsPair LargestconsecutiveAscElements(int n, int A[]);
void lexicographicPermute(int n);
void reversePermutationElements(int l, int r, int A[]);
int stepForwardFactorial(int n);

int main() {
    int n = 0;
    printf("Lexicographic Permute Alghorithm to get all permutations\n\n"); 
    while (n <= 0) {
        printf("Please insert a non-zero positive integer value: ");
        scanf("%d", &n);
    }
    printf("\n");

    lexicographicPermute(n);

    return 0;
}

ElementsPair LargestconsecutiveAscElements(int n, int A[]) {
    Element largestMinorElement = { -1, -1 };
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            largestMinorElement.value = A[i];
            largestMinorElement.pos = i;
            break;
        }
    }
    Element higherThanLargestMinorElement = { A[largestMinorElement.pos + 1], largestMinorElement.pos + 1 };
    ElementsPair consecutiveAscElements = { largestMinorElement, higherThanLargestMinorElement };

    return consecutiveAscElements;
}

void reversePermutationElements(int l, int r, int A[]) {
    while (l < r) {
        int temp = A[r];
        A[r] = A[l];
        A[l] = temp;
        l++; 
        r--;
    }
}

int stepForwardFactorial(int n) {
    int x = 1;
    int fact = 1;

    while (x <= n) {
        fact = fact * x;
        x++;
    }

    return fact;
}

void lexicographicPermute(int n) {
    int permutation[n];
    int permutationCounter = 1;
    int permutationsNumber = stepForwardFactorial(n);
    
    // Initializing first permutation
    printf("Permutations in lexicographic order:\n");
    for (int i = 0; i < n - 1; i++) {
        permutation[i] = i + 1;
        printf("%d ", permutation[i]);
    }
    permutation[n - 1] = n;
    printf("%d\n", permutation[n - 1]);
    
    while (permutationCounter <= permutationsNumber) {
        // Get the two consecutive elements in increasing order
        ElementsPair pair = LargestconsecutiveAscElements(n, permutation);
        Element fst = pair.first; 
        Element scd = pair.second;

        // If they doesn't exist, stop
        if (fst.pos == -1 || scd.pos == -1) break;

        // Find the largest j element such that A[i] < A[j] where j >= i + 1
        Element higherThanFirst = { scd.value, scd.pos };
        for (int j = n - 1; j > scd.pos; j--) {
            if (permutation[j] > fst.value && permutation[j] <= scd.value) {
                higherThanFirst.value = permutation[j];
                higherThanFirst.pos = j;
            }
        }
        
        // Swap A[i] and A[j] elements
        permutation[fst.pos] = higherThanFirst.value;
        permutation[higherThanFirst.pos] = fst.value;

        // Reverse all elements order from A[i + 1] to A[n - 1] inclusive
        reversePermutationElements(scd.pos, n - 1, permutation);

        // Print the permutation
        for (int i = 0; i < n - 1; i++) printf("%d ", permutation[i]);
        printf("%d\n", permutation[n - 1]);
        // Increase permutations counter
        permutationCounter++;
    }

    printf("\nTotal: %d\n\n", permutationsNumber);
}
