#include<vector>
#include<stdio.h>
using namespace std;

void print_vec(vector<int> vec){
    for (int i = 0;i < vec.size();i++)
        printf("%d \n",vec[i]);
}

int get_n(int t, int sum){
    int n;
    for(n = 1;n <= sum/2+1;n++)
        if((2*t+n-1)*n == 2*sum)
            return n;
    return 0;

}

int get_t(int n, int sum){
    int t;
    for(t = 1;t <= sum/2+1;t++)
        if((2*t+n-1)*n == 2*sum)
            return t;
    return 0;

}

vector<int> get_array(int start, int length){
    vector<int> result;
    for (int i = 0;i < length;i++)
        result.push_back(start+i); 
    
    return result; 

}



vector<vector<int> > FindContinuousSequence(int sum) {
    
    int max_length = 0, start = 0;
    vector<int> vec_tmp;
    vector<vector<int> > vec;
    for(int i = 1;i <= sum/2+1; i++){
        max_length = get_n(i, sum);
        if(max_length != 0){
            start = i;
            vec_tmp = get_array(start, max_length);
            print_vec(vec_tmp);
            vec.push_back(vec_tmp);
            break;
        }
    }

//    printf("%d %d\n", max_length, start);
    int t = 0, length = 0;
    for(int i = max_length;i > 1; i--){
        t = get_t(i, sum);
        if(t != 0){
            length = i;
            vec_tmp = get_array(t, i);
            print_vec(vec_tmp);
            vec.push_back(vec_tmp);
//           printf("%d %d\n", length, t);
        }
    }
    return vec;

}







int main(){
    int sum = 3;
    FindContinuousSequence(sum);
}
