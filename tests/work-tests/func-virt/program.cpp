#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Base class with virtual function
class Base {
public:
    virtual void doWork() = 0;
};

class Predictable : public Base {
public:
    void doWork() override {
        // Predictable work
    }
};

class Unpredictable : public Base {
public:
    void doWork() override {
        // Unpredictable work
    }
};

class Mixed : public Base {
public:
    void doWork() override {
        // Mixed work
    }
};

// Function to test predictable virtual function calls
void testPredictable(std::vector<Base*>& objects, int n) {
    for (int i = 0; i < n; ++i) {
        objects[i % objects.size()]->doWork();
    }
}

// Function to test unpredictable virtual function calls
void testUnpredictable(std::vector<Base*>& objects, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        objects[rand() % objects.size()]->doWork();
    }
}

// Function to test mixed virtual function calls
void testMixed(std::vector<Base*>& objects, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0) {
            objects[0]->doWork();
        } else {
            objects[rand() % objects.size()]->doWork();
        }
    }
}

int main() {
    int n = 1000;  // Number of iterations

    printf("\nfunc-virt test beginning!\n\n");

    // Create objects
    Predictable predictable;
    Unpredictable unpredictable;
    Mixed mixed;

    // Create vector of base class pointers
    std::vector<Base*> objects = {&predictable, &unpredictable, &mixed};

    // Measure time for predictable virtual function calls
    clock_t start = clock();
    testPredictable(objects, n);
    clock_t end = clock();
    std::cout << "Time for predictable virtual function calls: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Measure time for unpredictable virtual function calls
    start = clock();
    testUnpredictable(objects, n);
    end = clock();
    std::cout << "Time for unpredictable virtual function calls: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Measure time for mixed virtual function calls
    start = clock();
    testMixed(objects, n);
    end = clock();
    std::cout << "Time for mixed virtual function calls: " 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
