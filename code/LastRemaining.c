#include<stdio.h>

int LastRemaining_Solution(int n, int m){
    if(n == 1)
        return 0;
    else
        return (LastRemaining_Solution(n-1, m) + m)%n;
}

int main(){
    int n = 15, m = 4;
    int res = LastRemaining_Solution(n, m);
    printf("%d\n",res);

}
