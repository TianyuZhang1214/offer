#include<string>
using namespace std;


int StrToInt(string str) {
    int length = str.length();
    if(length == 0)
        return 0;
    printf("%d\n", length);
    char* ptr = &str[0];
    int tag = 1;
    int tmp;
    int re = 0;
    if((int)(*ptr) == 32)
        ++ptr;
    if((int)(*ptr) == 45){
        tag = -1;
        ++ptr;
    }
    if((int)(*ptr) != 45 && (int)(*ptr) != 43 && (int)(*ptr) != 32 &&(int)(*ptr)<48 \
    &&(int)(*ptr) > 57)
        return 0;
    while(*ptr!='\0'){
        tmp = (int)(*ptr);
        if(tmp > 47 and tmp < 58)
            re = 10*re + (tmp-48);
        else
            return 0;
//        printf("%c %d\n",*ptr, re);
        ++ptr;
    }
    return re*tag;

}




int main(){
    string str = " -0123456789";

    int re = StrToInt(str);
    printf("%d\n",re);

}
