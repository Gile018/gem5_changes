#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("\ncond-else test beginning!\n\n");
    int a = 5;
    if(a > 6) {
        a++;
    } else {
        a--;
    }
    return 0;
}