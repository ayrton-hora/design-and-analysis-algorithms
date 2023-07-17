#include <stdio.h>

int sequentialSearchWithSentinel(int * array, int size, int key);

int main() {
    int A[6] = {0, 3, 1, 6, 8, 5};
    int arraySize = sizeof(A) / sizeof(A[0]);
    
    printf("Sequential Search With Sentinel\n");

    printf("Array: [");
    for (int j = 0; j < arraySize - 1; j++) {
        printf("%d, ", A[j]);
    }
    printf("%d]\n", A[arraySize - 1]);

    int key;
    printf("Type the Key to be searched in Array: "); scanf("%d", &key);

    int index = sequentialSearchWithSentinel(A, arraySize, key);

    printf("Index of Key '%d' in Array: %d\n", key, index);

    return 0;
}

int sequentialSearchWithSentinel(int * array, int size, int key) {
    if (array[size - 1] == key)
        return size - 1;

    array[size - 1] = key;

    int i = 0;
    while (array[i] != key)
        i++;
    
    if (i < size - 1)
        return i;
    
    else 
        return -1;
}
