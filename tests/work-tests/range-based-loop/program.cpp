#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

int main(int argc, char* argv[]) {
    printf("\nrange-based loop test beginning!\n\n");
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int sum;
    for(int i = 0; i < 200; i++) {
        sum = 0;
        for(int num: numbers) {
            sum += sum;
        }
    }

}