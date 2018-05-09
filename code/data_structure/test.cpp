#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){
    int *a = (int*)malloc(sizeof(int));
    *a = 1;
    int *b = a;

    free(b);
//    free(a);

    printf("a: %d\n", *a);
    printf("b: %d\n", *b);
}


