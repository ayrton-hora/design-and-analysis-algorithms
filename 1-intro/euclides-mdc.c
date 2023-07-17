#include <stdio.h>

int mdc(int m, int n) {
    int r;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}


int main() {
    int m, n;
    
    printf("Insert to non-negative integer values:\n");
    printf("First value: "); scanf("%d", &m);
    printf("Second value: "); scanf("%d", &n);

    if (m < 0 || n < 0) {
        printf("Both value must be a non-negative integer\n");
        return 1;
    }

    if (m == 0 && n == 0) {
        printf("Both values cannot be equal to zero\n");
        return 1;
    }

    int r;
    r = mdc(m, n);
    printf("The maximum comum divisor of %d and %d is: %d\n", m, n, r);

    return 0;
}
