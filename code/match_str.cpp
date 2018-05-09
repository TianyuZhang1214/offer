#include<stdio.h>
#include<stdlib.h>
using namespace std;
bool match_one(char* str, char* pattern){
    if(*str == '\0' &&*pattern == '\0')
        return true;
    if(*str == '\0' && *pattern != '\0')
        return false;
    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern+1) == '*')
        if(*str == *pattern || *pattern == '.')
            return match_one(str, pattern+2)||match_one(str+1, pattern+2)||match_one(str+1, pattern);
        else{
            return match_one(str, pattern+2);
        }
    if(*str == *pattern || *pattern == '.')
        return match_one(str+1, pattern+1);
    return false;
}

bool match(char* str, char* pattern)
{
    if(str == NULL || pattern == NULL)
        return false;
    return match_one(str, pattern);
}


int main(){
    char *str = ",,";
    char *pattern = ".";
    bool res = match(str, pattern);
    printf("result: %d.\n",res);

}


