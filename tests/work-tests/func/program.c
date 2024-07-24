#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function with predictable branches
void predictable_branches(int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Even branch
        } else {
            // Odd branch
        }
    }
}

// Function with unpredictable branches
void unpredictable_branches(int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) {
            // Random branch
        } else {
            // Random branch
        }
    }
}

// Function with mixed branches
void mixed_branches(int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            // Predictable branch
        } else if (rand() % 2 == 0) {
            // Unpredictable branch
        } else {
            // Unpredictable branch
        }
    }
}

int main() {
    int n = 10000;  // Number of iterations
    printf("\nfunc test beginning!\n\n");
    // Measure time for predictable branches
    clock_t start = clock();
    predictable_branches(n);
    clock_t end = clock();
    printf("Time for predictable branches: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Measure time for unpredictable branches
    start = clock();
    unpredictable_branches(n);
    end = clock();
    printf("Time for unpredictable branches: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Measure time for mixed branches
    start = clock();
    mixed_branches(n);
    end = clock();
    printf("Time for mixed branches: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
