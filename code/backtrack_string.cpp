#include<iostream>
using namespace std;

bool isPath(char* matrix, int rows, int cols, char* str, int i, int j, bool *rcd){
    if(*str == '\0') return true;
    if(i<0|| i >= cols|| j<0|| j>=rows|| matrix[i*cols+j]!=*str|| rcd[i*cols+j] == 1) return false;
    rcd[i*cols+j] = 1;
    if(isPath(matrix, rows, cols, str+1, i-1, j, rcd)
    ||isPath(matrix, rows, cols, str+1, i, j-1, rcd)
    ||isPath(matrix, rows, cols, str+1, i+1, j, rcd)
    ||isPath(matrix, rows, cols, str+1, i, j+1, rcd)){
        return true;
    }
    rcd[i*cols+j] = 0;
    return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(!matrix|| !str || rows==0 || cols ==0 ) return false;
    bool *rcd=new bool[rows*cols]();
    int i,j;
    for(i=0; i<cols; i++)
        for(j=0; j<rows; j++)
            if(isPath(matrix, rows, cols, str, i, j, rcd)) return true;
    return false;
}

int main(){
    char *data = "ABCESFCSADEE";
    char *str = "SEE";
    int cols = 3;
    int rows = 4;
    bool res = hasPath(data, 3, 4, str);

    cout<<res<<endl;
    return 0;
}
