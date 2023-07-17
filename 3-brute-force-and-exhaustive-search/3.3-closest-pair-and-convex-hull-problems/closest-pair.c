#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

float bruteForceClosestPair(struct point pairs[], int n);

float min(float a, float b);

int main() {
    struct point points[] = {
        {1.0, 2.0}, 
        {3.0, 4.5}, 
        {9.0, 5.4}, 
        {6.1, 4.0}
    };

    int numPoints = sizeof(points) / sizeof(points[0]);

    printf("Pairs of points:\n");
    for (int i = 0; i < numPoints - 2; i++) {
        printf("(%.2f, %.2f), ", points[i].x, points[i].y);
    }
    printf("(%.2f, %.2f)\n", points[numPoints - 1].x, points[numPoints - 1].y);

    float d = bruteForceClosestPair(points, numPoints);

    printf("The distance between the closest pairs is: %.2f\n", d);

    return 0;
}

float min(float a, float b) {
    if (a <= b)
        return a;
    
    else
        return b;
}

float bruteForceClosestPair(struct point pairs[], int n) {
    float d = __FLT_MAX__;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            d = min(d, pow((pairs[i].x - pairs[j].x), 2) + pow((pairs[i].y - pairs[j].y), 2));
        }
    }

    return sqrt(d);
}
