#include <stdio.h>
#include <math.h>

int binarySearch(int * A, int size, int key);

int main() {
    int integerArray[10];
    int arraySize, key;

    for (int i = 0; i < 9; i++) {
        printf("Insert the %dº key of the Array: ", i + 1);
        scanf("%d", &integerArray[i]);
    }

    printf("Insert the key to be searched into Array: ");
    scanf("%d", &key);

    arraySize = sizeof(integerArray) / sizeof(integerArray[0]);

    int index = binarySearch(integerArray, arraySize, key);

    printf("\nIndex of Key '%d' in the Array is: %d\n", key, index);

    return 0;
}

int binarySearch(int * A, int size, int key) {
    int left, middle, right;

    left = 0;
    right = size - 1;
    while (left <= right) {
        middle = (int) floor(left + right) / 2;

        if (key == A[middle]) return middle;

        else if (key < A[middle]) right = middle - 1;
        
        else left = middle + 1;
    }

    return -1;
}
