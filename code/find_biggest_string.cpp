#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int find_small(int num1, int num2){
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    string tmp1 = str1 + str2;
    string tmp2 = str2 + str1;
    printf("%s\n",tmp1.c_str());
    printf("%s\n",tmp2.c_str());
    if(tmp1 < tmp2) return num1;
    else return num2;
}


string PrintMinNumber(vector<int> numbers) {
    string str;
    for(int i = 0;i < numbers.size();++i){
        for(int j = i + 1;j < numbers.size();++j){
            int tmp = find_small(numbers[i], numbers[j]);
//            printf("%d\n",tmp);
            if(tmp == numbers[i]) continue;
            numbers[j] = numbers[i];
            numbers[i] = tmp;
        }
    }
    for(int i = 0;i < numbers.size();++i){
        stringstream stream;
        stream << numbers[i];
        str += stream.str();
        stream.clear();
    }
    
    return str;
}

int main(){
    vector<int> test;
    test.push_back(5);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(1);

    string result = PrintMinNumber(test);
    printf("%s\n",result.c_str());

}
