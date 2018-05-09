#include<vector>
#include<stdio.h>
using namespace std;

bool binary_search(vector<int> array,int num, int start){
    int result;
//    int start = 0; 
    int end = array.size() - 1;
    int mid = end/2;
    while(start <= end){
        mid = (start+end)/2;
        if(array[mid] == num)
            return true;
        else if(array[mid] > num)
            end = mid-1;
        else
            start = mid+1;
    }
    return false;
}



vector<int> FindContinuousSequence(vector<int> array,int sum) {
    vector<int> result;
    if(array.size()<2)
        return result;
    int length = array.size();
    int search_item;
    bool judge;
    int tmp1=0, tmp2=0;
    for(int i =0;i < length;i++){
        int search_item = sum - array[i];
        if(search_item < array[i])
            break;
        judge = binary_search(array, search_item, i+1);
        if(judge == 1)
            if(tmp1*tmp2 == 0 || tmp1*tmp2 > array[i]*search_item){
                tmp1 = array[i];
                tmp2 = search_item;
            }
    }
    if(tmp1 == 0)
        return result; 
    result.push_back(tmp1);
    result.push_back(tmp2);
    return result;


}

int main(){
    int sum = 17;
    int length = 2;
//    int arr = (int)malloc(sizeof(int));
//    int arr[length] = {1,2,3,4,5,6,7,8,9,10};
    int arr[6] = {1,2,4,7,11,16};
    vector<int> vec;
//    for(int i = 0; i<length;i++)
//        vec.push_back(i); 
    
    for(int i = 0; i<sizeof(arr)/sizeof(int);i++)
        vec.push_back(arr[i]); 

    vector<int> result =  FindContinuousSequence(vec,sum);
    for (int i = 0;i<result.size();i++)
        printf("%d\n",result[i]);


}
