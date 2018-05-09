#include<stdio.h>


int Add(int num1, int num2)
{
    while(num2 != 0){
        int tmp = num1^num2;
        num2 = (num1&num2)<<1;
        num1 = tmp;
    }
    return num1;

}


int main(){
    int a = 6, b = 7;
    int c = Add(a,b);
    printf("%d\n",c);

}
