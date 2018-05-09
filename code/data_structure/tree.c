#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//original_tree:ABDG##H###CE#I##F##
typedef struct TreeNode{
    char val;
    struct TreeNode *left, *right;
}TreeNode , *Tree;

void create_tree(Tree *T){
    char data;
    cin >> ch;
    if(data == '#')
        *T = NULL;
    else{
        *T = (Tree)malloc(sizeof(TreeNode));
        (*T)->val = data;
        create_tree(&(*T)->left);
        create_tree(&(*T)->right);
    }
}

void operation1(int val){
    printf("%c ", val);
}

void operation2(int val, int level){
    printf("%c at the %c stage.\n", val, level);
}


void pre_order(Tree t, int level){
    if(t == NULL) return;
    operation2(t->val, level);

    pre_order(t->left, level+1);
    pre_order(t->right, level+1);

}

void in_order(Tree t, int level){
    if(t == NULL) return; in_order(t->left, level+1);
    operation2(t->val, level);
    in_order(t->right, level+1);
}

void post_order(Tree t, int level){
    if(t == NULL) return;
    post_order(t->left, level+1);
    post_order(t->right, level+1);
    operation2(t->val, level);
}
bool IsBalanced_Solution(TreeNode* pRoot) {
    if(pRoot == null)
        return 1
    int depth_left = 0;
    int depth_right = 0;
    return get_tree_length(pRoot->left, depth_left) && get_tree_length(pRoot->right, depth_right)

}
bool get_tree_length(TreeNode* pRoot, int* depth){
    if(pRoot == NULL){
        *depth = 0;
        return true;
    }
    int depth_left, depth_right;
    bool left = get_tree_length(pRoot->left, depth_left);
    bool right = get_tree_length(pRoot->left, depth_right);
   
    if(left && right)
        depth += (left > right?left:right);
    return abs(left - right) > 1 ? false:true;
}

int main(){
    int level = 1;
    Tree t = NULL;
    printf("Please input tree in pre-order: \n");
    create_tree(&t);
}

