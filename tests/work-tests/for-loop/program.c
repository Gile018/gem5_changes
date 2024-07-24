#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    printf("\nfor-loop test beginning!\n\n");
    int a = 0;
    int b = 2;
    int c = 3;
    for(int i = 0; i < 1000; i++) {
        a = 0;
        a = b + c;
        b = c;
        c = 5;
    }
}