#include <stdio.h>

void swap(int *a , int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv){
    int a = 3;
    int b = 4;
    swap(&a, &b);
    printf("%d %d.\n",a,b);
}


