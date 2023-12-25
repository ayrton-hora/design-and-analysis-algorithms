#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct IntTuple {
    int a;
    int b;
} IntTuple;

void * johnsonTrotter(int n);
int stepForwardFactorial(int n);
IntTuple findMobiles(int * permutation, int elements, char * arrows);

int main() {
    int n = 0;
    printf("Johnson Trotter Alghorithm to get all permutations\n\n"); 
    while (n <= 0) {
        printf("Please insert a non-zero positive integer value: ");
        scanf("%d", &n);
    }
    printf("\n");

    johnsonTrotter(n);

    return 0;
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

IntTuple findMobiles(int * permutation, int elements, char * arrows) {
    // Find smallest number
    int smallestElement = __INT_MAX__;
    int smallestElementPos = -1;
    for (int i = 0; i < elements; i++) {
        if (permutation[i] < smallestElement) {
            smallestElement = permutation[i];
            smallestElementPos = i;
        }
    }
    
    // Find largest mobile
    int largestMobile = -1;
    int largestMobilePos = -1;
    for (int i = 0; i < elements; i++) {
        // Mobile condition trigger
        if (permutation[i] > smallestElement && i > smallestElementPos && arrows[i] == 'L') {
            // Check if it's larger than current
            if (permutation[i] > largestMobile) {
                largestMobile = permutation[i];
                largestMobilePos = i;
            }
        }
        
        // Mobile condition trigger
        else if (permutation[i] > smallestElement && i < smallestElementPos && arrows[i] == 'R') {
            // Check if it's larger than current
            if (permutation[i] > largestMobile) {
                largestMobile = permutation[i];
                largestMobilePos = i;
            }
        }
    }

    IntTuple largestMobileValues = { largestMobile, largestMobilePos };

    return largestMobileValues;
}

void * johnsonTrotter(int n) {
    char arrows[n];
    int permutationNumber = 1;
    int permutation[n];
    int answersNumber = stepForwardFactorial(n);
    
    // Initialize the first permutation with 1..n and numbers with Left Arrow ('L')
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        arrows[i] = 'L';
    }

    printf("Permutations:\n");
    while (permutationNumber <= answersNumber) {
        for (int i = 0; i < n - 1; i++) 
            printf("%d ", permutation[i]);
        printf("%d\n", permutation[n - 1]);

        // Get largest mobile info
        IntTuple largestMobileValues = findMobiles(permutation, n, arrows);
        int largestMobile = largestMobileValues.a;
        int largestMobilePos = largestMobileValues.b;

        // Check if the permutation hasn't a mobile element
        if (largestMobile == -1) 
            break;

        // Swap the both value and arrows of largest element with the adjascent element
        char switchPos = arrows[largestMobilePos];
        if (switchPos == 'L') {
            permutation[largestMobilePos] = permutation[largestMobilePos - 1];
            arrows[largestMobilePos] = arrows[largestMobilePos - 1];

            permutation[largestMobilePos - 1] = largestMobile;
            arrows[largestMobilePos - 1] = switchPos;
        }

        else {
            permutation[largestMobilePos] = permutation[largestMobilePos + 1];
            arrows[largestMobilePos] = arrows[largestMobilePos + 1];

            permutation[largestMobilePos + 1] = largestMobile;
            arrows[largestMobilePos + 1] = switchPos;
        }

        // Reverse the arrow direction of all the elements that are larger than the largest mobile
        for (int i = 0; i < n; i++)
            if (permutation[i] > largestMobile)
                arrows[i] = (arrows[i] == 'L' ? 'R' : 'L');

        // Increase the permutations counter
        permutationNumber++;
    }

    printf("\nPermutations Number: %d\n\n", answersNumber);

    return NULL;
}
