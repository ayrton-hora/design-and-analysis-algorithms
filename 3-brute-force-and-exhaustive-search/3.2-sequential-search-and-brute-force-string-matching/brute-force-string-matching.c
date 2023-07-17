#include <stdio.h>

int bruteForceStringMatching(char * text, int n, char * pattern, int m);

int main() {
    printf("Brute Force String Matching\n");

    char text[] = "projeto e analise de algoritmos";
    int n = sizeof(text) / sizeof(text[0]);

    char pattern[] = "analise";
    int m = sizeof(pattern) / sizeof(pattern[0]);

    printf("Text: '%s'\n", text);
    printf("Pattern: '%s'\n", pattern);

    int index = bruteForceStringMatching(text, n, pattern, m);

    printf("Index of Pattern begin: %d\n", index);
    return 0;
}

int bruteForceStringMatching(char * text, int n, char * pattern, int m) {
    int i, j;
    for (i = 0; i < n - m; i++) {
        j = 0;
        while ((j < m) && (pattern[j] == text[i + j]))
            j++;
        
        if (j == (m - 1))
            return i;
    }

    return -1;
}