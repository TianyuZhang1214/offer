#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstring>
#include<string.h>
#include<deque>
using namespace std;

string LeftRotateString(string str, int n) {
    if(str == "") return str;
    int length = str.length();
    int tag = n%length;
    if(tag == 0) return str;
    string right = str.substr(0, tag);
    string left = str.substr(tag, length);
    left.append(right);
    printf("%s\n",left.c_str());
    return left;
}

string ReverseSentence(string str) {  
    int n=str.size();
    if(n==0)return str;
//    bool flag=false;
    string s="";
    string tmp="";
    for(int i=0;i<n;i++){
        if(str[i]==' '){
//            if(flag)
            s=tmp+s;
//            flag=false;
            tmp="";
            s=str[i]+s;
//            printf("%s\n", s.c_str());
        }else{
//            printf("%c\n", str[i]);
            tmp+=str[i];
//            flag=true;
        }  
    }  
    s=tmp+s;  
    return s;  
}  

int main(){
    int n = 2;

    string str = "Jixu is a cute Ducky.";
    string result = ReverseSentence(str);
    printf("%s\n", result.c_str());
    return 1;
}


