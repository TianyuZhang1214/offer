
bool duplicate(int numbers[], int length, int* duplication) {
    if(length == 0)
        return false;
    int *list;
    list = (int*)malloc(length*sizeof(int));
    memset(list, 0, sizeof(int)*length);
    for (int i = 0;i < length;i++){
        ++list[numbers[i]];
        if(list[numbers[i]] > 1)
            *duplication = numbers[i];
            return true;
    }
    return false;
        
}

int main(){

    int array[10] = {}





}
