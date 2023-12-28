#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Element {
    int value;
    int pos;
} Element;

void * johnsonTrotter(int n);
int stepForwardFactorial(int n);
Element largestMobile(int * permutation, int elements, char * arrows);

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

Element largestMobile(int * permutation, int elements, char * arrows) {
    // Identify all permutation mobiles
    int m = 0;
    Element mobiles[elements];
    for (int i = 0; i < elements; i++) {
        // Border elements first check condition
        if (!(i == 0 && arrows[i] == 'L') && !((i == elements - 1) && arrows[i] == 'R')) {
            // First element
            if ((i == 0) && (permutation[i] > permutation[i + 1])) {
                Element mobile = { permutation[i], i };
                mobiles[m] = mobile;
                m++;
                continue;
            }
            // Last element
            else if ((i == elements - 1) && (permutation[i] > permutation[i - 1])) {
                Element mobile = { permutation[i], i };
                mobiles[m] = mobile;
                m++;
                continue;
            }
            // Middle element pointing to left
            else if ((arrows[i] == 'L') && (permutation[i] > permutation[i - 1])) {
                Element mobile = { permutation[i], i };
                mobiles[m] = mobile;
                m++;
                continue;
            }
            // Middle element pointing to right
            else if ((arrows[i] == 'R') && (permutation[i] > permutation[i + 1])) {
                Element mobile = { permutation[i], i };
                mobiles[m] = mobile;
                m++;
                continue;
            }
        }
    }

    // Find the largest mobile of group
    Element largestMobile = { -1, -1 };
    for (int i = 0; i < m; i++) {
        if (mobiles[i].value > largestMobile.value) {
            largestMobile.value = mobiles[i].value;
            largestMobile.pos = mobiles[i].pos;
        }
    }
    return largestMobile;
}

void * johnsonTrotter(int n) {
    char arrows[n];
    int permutationCounter = 1;
    int permutation[n];
    int permutationsNumber = stepForwardFactorial(n);
    
    // Initialize the first permutation with 1..n and numbers with Left Arrow ('L')
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        arrows[i] = 'L';
    }

    printf("Permutations:\n");
    while (permutationCounter <= permutationsNumber) {
        for (int i = 0; i < n - 1; i++) printf("%d ", permutation[i]);
        printf("%d\n", permutation[n - 1]);

        // Get largest mobile info
        Element largestMobileElement = largestMobile(permutation, n, arrows);
        int largestMobile = largestMobileElement.value;
        int largestMobilePos = largestMobileElement.pos;

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
        // SwitchPos == 'R'
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
        permutationCounter++;
    }

    printf("\nTotal: %d\n\n", permutationsNumber);

    return NULL;
}
