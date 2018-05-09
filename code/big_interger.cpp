#include<iostream>
using namespace std;

char* multi(char* a, char* b){
    int length_a = 0;
    int length_b = 0;
    while(*(a++) != '\0') ++length_a;
    while(*(b++) != '\0') ++length_b;
    a -= (length_a+1);
    b -= (length_b+1);

    int i, j, k, m, tag, tmp_1, res;
    char *c = (char*)malloc(sizeof(char)*(length_a+length_b+1));
    for(i = 0; i< length_a+length_b+1;++i) c[i] = '0';

    tag = 0;
    char *tmp = (char*)malloc(sizeof(char)*(length_b+1));

    for(i= length_a-1;i>=0;--i){
        for(m = 0; m < length_b+1;++m) tmp[m] = '0';
        for(j = length_b-1; j>=0; --j){
            res = (int)(a[i]-'0') * (int)(b[j]-'0') + tag;
            tmp_1 = res%10;
            tag = res/10;
            tmp[j+1] = tmp_1 + '0';
        }
        tmp[0] = tag + '0';
        tag = 0;
        for(k = length_b;k >= 0;--k){
            res = (int)(c[k+i+1] - '0') + (int)(tmp[k] - '0') + tag;
            tmp_1 = res%10;
            tag = res/10;
            c[k+i+1] = tmp_1 + '0';
        }
        c[i+1] = tag + '0';
        tag = 0;
    }
    while(*c == '0') ++c;
    return c;

}

int main(){
    char *a = "12345";
    char *b = "12345";
    char *c = multi(a, b);
    cout<<c<<endl;

}


