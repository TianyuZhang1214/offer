#include<stdio.h>

int min(int a, int b, int c){
    if(a < b)
        return a<c? a:c;
    else 
        return b<c? b:c;
}

int GetUglyNumber_Solution(int index) {
    int arr[index];
     
    arr[0] = 1;
    int multi1 = 0;
    int multi2 = 0;
    int multi3 = 0;
        
    for(int i = 1;i<index;i++){
        int min_value = min(arr[multi1]*2, arr[multi2]*3, arr[multi3]*5);
        arr[i] = min_value;
        while(arr[multi1]*2 <= min_value)
            ++multi1;

        printf("multi1: %d\n", multi1);
        while(arr[multi2]*3 <= min_value)
            ++multi2;
        printf("multi2: %d\n", multi2);
        while(arr[multi3]*5 <= min_value)
            ++multi3;
        printf("multi3: %d\n", multi3);
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    
    return arr[index-1];

}




int main(){

    int res = GetUglyNumber_Solution(20);
    printf("%d\n", res);


}
