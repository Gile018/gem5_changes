#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("\ninfinite-loop test beginning!\n\n");
    int a = 0;
    int b = 2;
    int c = 3;
    int i = 0;
    while(1==1) {
        a = 0;
        a = b + c;
        b = c;
        i++;
        if(i == 727) break;
    }

}