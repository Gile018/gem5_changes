#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function definitions
void predictableFunction() {
    // Predictable work
}

void unpredictableFunction() {
    // Unpredictable work
}

void mixedFunction() {
    // Mixed work
}

// Function to test predictable function pointer calls
void testPredictable(std::vector<void(*)()>& funcs, int n) {
    for (int i = 0; i < n; ++i) {
        funcs[i % funcs.size()]();
    }
}

// Function to test unpredictable function pointer calls
void testUnpredictable(std::vector<void(*)()>& funcs, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        funcs[rand() % funcs.size()]();
    }
}

// Function to test mixed function pointer calls
void testMixed(std::vector<void(*)()>& funcs, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0) {
            funcs[0]();
        } else {
            funcs[rand() % funcs.size()]();
        }
    }
}

int main() {
    int n = 1000;  // Number of iterations
    
    printf("\nfunc-ptrs test beginning!\n\n");

    // Create vector of function pointers
    std::vector<void(*)()> funcs = {predictableFunction, unpredictableFunction, mixedFunction};

    // Measure time for predictable function pointer calls
    clock_t start = clock();
    testPredictable(funcs, n);
    clock_t end = clock();
    std::cout << "Time for predictable function pointer calls: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Measure time for unpredictable function pointer calls
    start = clock();
    testUnpredictable(funcs, n);
    end = clock();
    std::cout << "Time for unpredictable function pointer calls: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Measure time for mixed function pointer calls
    start = clock();
    testMixed(funcs, n);
    end = clock();
    std::cout << "Time for mixed function pointer calls: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
