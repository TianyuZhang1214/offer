#include<vector>
#include<stdio.h>
#include<iostream>

using namespace std;

//int InversePairsCore(vector<int> &copy,vector<int> &data,int start, int end){  
//        if(start == end)  
//            return 0;  
//        int center = (end - start) / 2;  
//          
//        int left = InversePairsCore(copy,data,start,start + center)%1000000007;  
//        int right = InversePairsCore(copy,data,start + center + 1,end)%1000000007;  
//          
//        printf("%d\n", (left + right + count)%1000000007);
//        
//        int i = start + center;  
//        int j = end;  
//        int copyIndex = end;  
//        int count = 0;  
//          
//        while(i >= start && j >= start + center + 1){  
//            if(data[i] > data[j]){  
//                copy[copyIndex--] = data[i--];  
//                count += j - start -center;  
//                if(count > 1000000007)  
//                    count %= 1000000007;  
//            }  
//            else{  
//                copy[copyIndex--] = data[j--];  
//            }  
//        }  
//          
//        while(i >= start)  
//            copy[copyIndex--] = data[i--];  
//        while(j >= start + center + 1)  
//            copy[copyIndex--] = data[j--];  
//          
//        for(int k = start; k <= end; k++)  
//            data[k] = copy[k];  
//          
//        printf("%d\n", (left + right + count)%1000000007);
//        return (left + right + count)%1000000007;  
//}
//
//
//int InversePairs(vector<int> data) {  
//        int length = data.size();  
//        if(length < 1)  
//            return 0;  
//        vector<int> copy(data);  
//        return InversePairsCore(copy,data,0,length - 1);  
//}  
      

int merge_search(vector<int> data, int start_pos, int end_pos){
    if(start_pos == end_pos)
        return 0;

    if(start_pos - end_pos == 1){
        printf("%d %d\n", data[start_pos], data[end_pos]);
        return data[start_pos] > data[end_pos] ? 1:0;
    } 
    
    int mid = (start_pos+end_pos)/2;
    int left = merge_search(data, start_pos, mid);
    int right = merge_search(data, mid+1, end_pos);
    int tag = 0;
    int i, j;
    for(i = start_pos; i <= mid; i++)
        for(j = mid+1; j <= end_pos; j++){
            printf("%d %d \n",data[i],data[j]);
            if(data[i] > data[j]) {
                ++tag; 
            }
        }
    printf("%d %d: %d %d %d\n", data[start_pos], data[end_pos], left, right, tag);
    return left+right+tag;

}
int InversePairs_mine(vector<int> data) {
    if(data.empty())
        return 0;
    int length = data.size();
    return merge_search(data, 0, length-1);
}


int main(){
    int arr[20] = {1,3,2,6,4,5,8,6,9,10,15,14,13,12,11,16,17,18,19,20};
    vector<int> vec;
    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++)
        vec.push_back(arr[i]);
    
//    int res = InversePairs(vec);
    int res1 = InversePairs_mine(vec);
//    printf("%d %d\n",res, res1);
    printf("%d\n", res1);
}
