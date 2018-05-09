#include<iostream>
using namespace std;

int sum_of_num(int x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int isPath(int rows, int cols, int k, int i, int j, bool *rcd){
    int sum = sum_of_num(i) + sum_of_num(j);
    if(i<0|| i >= cols|| j<0|| j >= rows|| sum > k||rcd[i*cols+j] == 1) return 0;
    else
        printf("[%d %d]\n",i,j);
    rcd[i*cols+j] = 1;
    return isPath(rows, cols, k, i-1, j, rcd) +
    isPath(rows, cols, k, i, j-1, rcd) +
    isPath(rows, cols, k, i+1, j, rcd) +
    isPath(rows, cols, k, i, j+1, rcd) + 1;
}

int movingCount(int k, int rows, int cols)
{
    printf("[%d %d]\n",rows,cols);
    if(rows==0 || cols ==0 ) return false;
    bool *rcd=new bool[rows*cols]();
    int i = 0;
    int j = 0;
    return isPath(rows, cols, k, i, j, rcd);
    return false;
}

int main(){
    int k = 10;
    int rows = 2;
    int cols = 100;

    int res = movingCount(k, rows, cols);
    printf("\n%d\n",res);
    return 0;
}
