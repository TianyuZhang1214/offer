#include<vector>
#include<iostream>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty()){
        return false;
    }

    int length = sequence.size();
    vector<int> leftchild;
    vector<int> rightchild;
    int root = sequence[length - 1];
    int i,j;

    for(i =0; i < length - 1;i++){
        if(sequence[i] < root)
            leftchild.push_back(sequence[i]);
        else
            break;
    }
    
    bool lefttag = true;
    
    for(j = i;j < length - 1;j++){
        if(sequence[j] < root)
            return false;
        else
            rightchild.push_back(sequence[j]);
    }

    bool righttag = true;
    
    if(i > 0)
        lefttag = VerifySquenceOfBST(leftchild);

    if(i< length - 1)
        righttag = VerifySquenceOfBST(rightchild);

    return lefttag&&righttag;
}

int main(){

    vector<int> tree1; 
    vector<int> tree2;

    int list1[7] = { 5,7, 6, 9, 11, 10, 8 };
    int list2[4] = { 7,4,6,5 };
    int i;
    
    for (i = 0;i < sizeof(list1)/sizeof(list1[0]);i++)
        tree1.push_back(list1[i]);

    for (i = 0;i < sizeof(list2)/sizeof(list2[0]);i++)
        tree2.push_back(list2[i]);


    
    bool result1 = VerifySquenceOfBST(tree1);
    cout << "tree1结果是：" ;
    cout << result1 << endl;
    cout << endl;

    bool result2 = VerifySquenceOfBST(tree2);
    cout << "tree2结果是：";
    cout << result2 << endl;
    cout << endl;

}
