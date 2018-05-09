#include<vector>
#include<iostream>
using namespace std;
void matrix(vector<int> A, int* C, int* D){
    int length = A.size();
    C[0] = 1;
    D[length-1] = 1;
    int i;
    for(i = 1;i < length;i++){
        C[i] = C[i-1]*A[i-1];
        D[length-1-i] = D[length-i]*A[length-i];
    }
    for(i = 0;i < length;i++)
        cout << "C[i]: " <<C[i]<<" D[i]: "<<D[i]<<endl;
}

vector<int> multiply(const vector<int>& A) {
    vector<int> B;
    int i;
    int length = A.size();
    int *C, *D;
    C = (int*)malloc(sizeof(int)*length);
    D = (int*)malloc(sizeof(int)*length);
    memset(C, 1, length);
    memset(D, 1, length);

    for(i = 0;i< A.size();i++)
        cout<<A[i]<<endl;
    matrix(A, C, D);
    for(i = 0 ;i<A.size();i++)
        B.push_back(C[i]*D[i]);
    return B;
}

int main(){
    vector<int> A, result;
    int i;
    for(i = 1;i < 10;i++)
        A.push_back(i);
    result = multiply(A); 

    for(i = 0;i< result.size();i++)
        cout<<result[i]<<endl;

}
