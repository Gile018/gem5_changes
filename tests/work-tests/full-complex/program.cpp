#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Base class for virtual functions
class Base {
public:
    virtual void process(int) = 0;
};

class Predictable : public Base {
public:
    void process(int x) override {
        if (x % 2 == 0) {
            // Predictable work for even x
        } else {
            // Predictable work for odd x
        }
    }
};

class Unpredictable : public Base {
public:
    void process(int x) override {
        // Unpredictable work based on random condition
        if (rand() % 2 == 0) {
            // Random branch
        } else {
            // Random branch
        }
    }
};

// Function prototypes
void functionA();
void functionB();
void functionC();

// Function pointers
std::vector<void(*)()> funcPtrs = {functionA, functionB, functionC};

// Virtual function pointers
std::vector<Base*> virtualFuncs;

// Complex loop function
void complexLoop(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Function pointer calls
        funcPtrs[rand() % funcPtrs.size()]();
        
        // Virtual function calls
        virtualFuncs[rand() % virtualFuncs.size()]->process(i);
        
        // Nested loops with complex branching
        for (int j = 0; j < 10; ++j) {
            if (i % 3 == 0) {
                if (j % 2 == 0) {
                    // Predictable branch
                } else {
                    // Predictable branch
                }
            } else {
                if (rand() % 2 == 0) {
                    // Unpredictable branch
                } else {
                    // Unpredictable branch
                }
            }
        }
    }
}

// Function definitions
void functionA() {
    // Simulate work
}

void functionB() {
    // Simulate work
}

void functionC() {
    // Simulate work
}

int main() {
    srand(time(NULL));
    
    printf("\nfull-complex test beginning!\n\n");

    // Initialize virtual function pointers
    Predictable p;
    Unpredictable u;
    virtualFuncs = {&p, &u};
    
    int n = 1000;  // Number of iterations
    
    // Measure time for complex loop
    clock_t start = clock();
    complexLoop(n);
    clock_t end = clock();
    std::cout << "Time for complex loop: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";
    
    return 0;
}
