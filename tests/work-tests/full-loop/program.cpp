#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

int main(int argc, char* argv[]) {
    printf("\nfull-loop test beginning!\n\n");
    int a = 0;
    int b = 2;
    int c = 3;

    for(int i = 0; i < 200; i++) {
        a++;
        int j = 0;
        while(j < 100) {
            b++;
            j++;
        }

        int k = 0;
        do {
            c++;
            k++;
        } while(k < 100);
    }

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int l = 0;
    while(1==1) {
        for(int num: numbers){
            a += num;
        }
        l++;
        if(l == 77) break;
    }

}