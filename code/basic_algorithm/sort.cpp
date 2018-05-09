#include<iostream>
using namespace std;

class Sort{
public:
    template<typename T>
    bool compare(T *data, int i, int j){
        return data[i] < data[j] ? true:false; 
    }

//    template<typename T>
//    bool (pf*)compare(T *data, int i, int j){
//    }

    template<typename T> 
    void swap(T *data, int i, int j){
        T tmp = *(data+i);
        *(data+i) = *(data+j);
        *(data+j) = tmp;
    }

    template<typename T> 
    void selection_sort(T *data, int length){
        T i, j;
        printf("length:%d\n",length);
        for(i=0;i<length;i++){
            int min = i;
            for(j = i+1;j<length;j++){
                printf("data[%d]:%d data[%d]:%d\n",i, data[i], j, data[j]);
                if(!compare(data, i, j)) min = j;
            }
            printf("min:%d\n",min);
            swap(data, i, min); 
        }
    }

    template<typename T> 
    void bubble_sort(T *data, int length){
        T i, j;
        for(i=0;i<length;i++){
            int min = i;
            for(j = i+1;j<length;j++)
                if(!compare(data, i, j)) swap(data, i, j); 
        }
    }

    template<typename T> 
    int partition(T *data, int low, int high){
        printf("low: %d high:%d.\n", low, high);
        int i = low, j = high + 1;
        while(true){
            while(compare(data, ++i, low)) if(i == high) break;
            while(compare(data, low, --j)) if(j == low) break;
            if(i >= j) break;
            swap(data, i, j);
        }
        swap(data, low, j); 
        return j; 
    }
   
    template<typename T> 
    void quick_sort(T *data, int low, int high){
        if(high<=low) return;
        int j = partition(data, low, high);
        quick_sort(data, low, j-1);
        quick_sort(data, j+1, high);
    }

    template<typename T> 
    void quick_sort_main(T *data, int length){
        quick_sort(data, 0, length-1); 
    }
   
    template<typename T> 
    void quick3way_sort(T *data, int low, int high){
        if(low>=high) return;
        int lt = low, i = low+1, gt = high;
        while(lt <= gt &&i <= high){
            if(data[i] < data[lt]) swap(data, lt++, i++);
            else if(data[i] > data[lt]) swap(data, i, gt--);
            else i++; 
        }
        quick3way_sort(data, low, lt-1); 
        quick3way_sort(data, gt+1, high); 
    }
    
    template<typename T> 
    void quick3way_sort_main(T *data, int length){
        quick3way_sort(data, 0, length-1); 
    }

    template<typename T> 
    void adjust(T* data, int length){
        int k = 1;
        while(2*k <= length+1){
            int j = 2*k;
            if(j < length+1 && compare(data, j-1, j)) ++j;
            if(compare(data, k-1, j-1)) swap(data, k-1, j-1);
            k *= 2;     
        }
    }
    
    template<typename T>
    void heap_sort(T* data, int length){
        for(int i = 0;i<length;i++){
            adjust(data, length - i-1);
            swap(data, 0, length-i-1);
        }
    }

    void insert_sort();
    void Shell_sort();
    void merge_sort();
    void heap_sort();
    void bucket_sort();
    void radix_sort();

};

int main(){
    
    int length = 10;

    int* data;
    data = (int*)malloc(length*sizeof(int));
    memset(data, 0, sizeof(int)*length);

    for(int i = 0;i < length;i++){
        data[i] = length - i;
        printf("%d ",data[i]);
    }
    printf("\n");
    Sort sort;
//    sort.bubble_sort<int>(data, length);
//    sort.quick3way_sort_main<int>(data, length);
    sort.heap_sort<int>(data, length);
    for(int i = 0;i < length;i++){
        printf("%d ",data[i]);
    }
        printf("\n");

}
