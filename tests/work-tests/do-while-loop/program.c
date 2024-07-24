#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    printf("\ndo-while test beginning!\n\n");
    int a = 0;
    int b = 2;
    int c = 3;
    int i = 0;

    do {
        a = 0;
        a = b + c;
        b = c;
        c = 5;
        i++;
    } while(i < 1000);

}