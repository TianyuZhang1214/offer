#include<stdio.h>
#include<iostream>

using namespace std;

bool isNumber(char str){
    if((int)(str) > 47 && (int)(str) < 58) return true;
    else return false;
}
int isSymble(char str){
    if(str == '+') return 1;
    else if(str == '-') return 2;
    else return 0;
}
bool isNumeric(char* str)
{   
    if(isNumber(*str)) 
        ++str;
    else{ 
        int sym = isSymble(*str);
        if(sym > 0) ++str;
        else return false;
    }
    while(*str != '\0'){
        if(isNumber(*str)) 
            ++str;
        else if(*str == 'e' || *str == 'E'){
            if(isNumber(*(str+1))) ++str;
            else{
                int sym = isSymble(*(str+1));
                if(sym == 2) str += 2;
                else return false;
            }
        }
        else if(*str == '.'){
            if(isNumber(*(str+1))) ++str;
            else return false;
        }
    return true;
    }
}
int main(){
    char *str1 = "+12349e98";
    char *str2 = "1.282e+11";
    char *str3 = "1282e-11";

    bool res = isNumeric(str2);
    cout << "res: "<<res<<endl;
}
