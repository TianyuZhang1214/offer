#include<vector>
#include<iostream>

using namespace std;

//vector<int> printMatrix(vector<vector<int> > matrix) {
//    vector<int> result;
//    int col1, row1 = 0;
//    int row2 = matrix.size(), col2 = matrix[0].size();
//        
//    while(true){
//        //from left top to right top
//        for(int i = col1; i< col2;i++){
//            result.push_back(matrix[row1][i]);
//            cout<<"col1: "<< i <<" matrix: "<<matrix[row1][i]<<" ";
//        }
//        row1++;
//        if(row1 >= row2) break;
//
//        //from right top to right bottom
//        for(int i = row1; i< row2;i++){
//            result.push_back(matrix[i][col2-1]);
////            cout<<i<<" ";
////            cout<<matrix[i][col2-1]<<" ";
//        }
//        col2--;
//        if(col1 >= col2) break;
//
//        //from right bottom to left bottom
//        for(int i = col2 - 1; i>= col1; i--){
//            result.push_back(matrix[row2-1][i]);
// //           cout<<i<<" ";
// //           cout<<matrix[row2-1][i]<<" ";
//        }
//        row2--;
//        if(row1 >= row2) break;
//
//        //from left bottom to left top
//        for(int i = row2 - 1; i >= row1; i--){
//            result.push_back(matrix[i][col1]);
////            cout<<i<<" ";
////          cout<<matrix[i][col1]<<" ";
//        }
//        col1++;
//        if(col1 >= col2) break;
//    }
//    return result;
//}

vector<int> printMatrix(vector<vector<int> > matrix) {
    int row1 = 0, row2 = matrix.size();
    int col1 = 0, col2 = matrix[0].size();
    vector<int> result;
    while (true)
    {
        for (int i = col1; i < col2; i++)
        {
            result.push_back(matrix[row1][i]);
    
        }
        row1++; 
        if (row1 >= row2)break; //循环终止条件
        
        for (int i = row1; i < row2; i++)
        {
            result.push_back(matrix[i][col2-1]);
    
        }
        col2--; 
        if (col1 >= col2)break;

        //从右往左打印
        for (int i = col2-1; i >= col1; i--)
        {
            result.push_back(matrix[row2-1][i]);
        
        }
        row2--; 
        if (row1 >= row2)break;

        //从下往上打印
        for (int i = row2-1; i >= row1; i--)
        {
            result.push_back(matrix[i][col1]);
        }
        col1++;
        if (col1 >= col2)break;

    }
    
    return result;
}
int main(){
    vector<vector<int> > matrix;
    vector<int> result;

    matrix.resize(4);
    for(int i = 0;i< 4;i++){
        matrix[i].resize(4);
    }
    for(int i = 0; i< 4;i++){
        for(int j = 0; j < 4;j++){
            matrix[i][j] = i*4+j;
//            cout<<matrix[i][j]<<" ";
        }
    }
    
    result = printMatrix(matrix);

    while (!result.empty())
    {
        cout << *(result.end()-1) << "  ";
        result.pop_back();
    }
 
    cout << endl;
    return 0;

}
