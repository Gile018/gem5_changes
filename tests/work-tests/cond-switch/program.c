#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    printf("\nswitch test beginning!\n\n");
    int a = 2;
    switch(a) {
        case 0: a -= 2; break;
        case 1: a += 2; break;
        case 2: a -= 1; break;
        default: a += 1; break;
    }
    return 0;
}