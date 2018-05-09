#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;

void swap(vector<int> *a ,vector<int> *b){
    vector<int> *tmp;
    *tmp = *a;
    *a = *b;
    *b = *tmp;
}

//void sort_value(vector<int> numbers, int length){
//    for(int i = 0;i<length - 1;i++)
//        if(numbers[i] > numbers[i+1])
//            (numbers[i]).swap(numbers[i+1]);
//            swap(&(numbers[i]),&(numbers[i+1]));
//}

bool IsContinuous(vector<int> numbers ) {
        int length = numbers.size();
        if(length > 5 || length == 0)
            return false;
        int count_zero = 0;
        sort(numbers.begin(), numbers.end());
        for (int i = 0;i<length-1;i++){
            if(numbers[i] == 0){
                ++count_zero;
//                printf("count_zero:%d\n",count_zero);
                continue;
            }
            if(count_zero > 4)
                return false;
            int def = numbers[i+1] - numbers[i];
//            cout<< numbers[i+1] <<" "<<numbers[i]<<endl;
//           printf("%d %d\n",def, count_zero);
            if(def > 5 || def == 0)
                return false;
            else if(def == 1)
                continue;
            else if(def >= 2 and diff <=5){
                count_zero -= diff - 1;
                if(count_zero < 0)
                    return false;
            }
        }
        return true;
}

int main(){
    
    int arr[5] = {6,1,4,0,8};
    vector<int> vec;
    for (int i = 0;i<5;i++)
        vec.push_back(arr[i]);

//    vector<int> *vec_ptr;
//    *vec_ptr = vec;
//    cout << vec[0] << endl;
//    printf("%d\n",tmp);
    bool tag = IsContinuous(vec);
    printf("%d\n",tag);

}





