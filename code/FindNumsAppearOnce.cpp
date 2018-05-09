#include<vector>
#include<stdio.h>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    if(data.empty())
        return;
    int group_tag = 0;
    for(int i=0;i<data.size();i++){
        group_tag ^= data[i];
    }

    int count_tag = 0;
    while((group_tag >> count_tag & 0x1) != 1)
        ++count_tag;
    
    int group = 1 << count_tag;


    for(int i = 0;i<data.size();i++){
        int data_tmp = data[i] >> count_tag;
        if((data_tmp & 0x1) == 0){
            *num1 ^= data[i];
        }
        else{ 
            *num2 ^= data[i];
        }
    }

}






int main(){
    int arr[20] = {1,2,3,4,1,2,3,5,6,7,8,9,5,6,7,8,10,11,11,10};
    vector<int> vec;
    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++)
        vec.push_back(arr[i]);

//    int res = InversePairs(vec);
    int num1,num2;
    num1 = 0;
    num2 = 0;
    FindNumsAppearOnce(vec, &num1, &num2);
//    printf("%d %d\n",res, res1);
    printf("%d %d\n", num1, num2);
}
