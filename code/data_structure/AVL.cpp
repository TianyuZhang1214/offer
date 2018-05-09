#include<stdio.h>
#include<stdlib.h>

typedef int elementType;
typedef struct node{
    elementType element;
    struct node *left;
    struct node *right;
    int treeHeight;
}tre,*pTree;

pTree find(pTree tree, elementType ele){
    if(!tree) return NULL;
    if(ele > tree->element) return find(tree->right, ele);
    else if(ele < tree->element) return find(tree->left, ele);
    else return tree;
}

pTree get_min_ele(pTree tree){
    if(tree){
        while(tree->left)
            tree = tree->left;
    }
    return tree;
}

pTree get_max_ele(pTree tree){
    if(tree){
        while(tree->right)
            tree = tree->right;
    }
    return tree;
}

pTree insert(pTree tree, elementType ele){
    if(!tree){
        pTree temp = (pTree)malloc(sizeof(tre));
        temp->element = ele;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if(ele < tree->element) tree->left = insert(tree->left, ele);
    else if(ele > tree->element) tree->right = insert(tree->right, ele);
    return tree;
}

void preOrderTraversal(pTree tree){
    if(tree){
        printf("%d ",tree->element); 
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}

pTree delete_ele(pTree tree, elementType ele){
    pTree temp;
    if(!tree) printf("Tree is NULL.\n");
    else{
        if(tree->element > ele) tree->left = delete_ele(tree->left, ele);
        else if(tree->element < ele) tree->right = delete_ele(tree->right, ele);
        else{
            if(tree->left && tree->right){
                temp = get_min_ele(tree->right);
                tree->element = temp->element;
                tree->right = delete_ele(tree->right, temp->element);
            }
            else{
                temp = tree;
                if(!tree->left) tree = tree->right; 
                else if(!tree->right) tree = tree->left;
                free(temp);
            }
        }
    }
    return tree;
}

//-------------------调整树为平衡二叉树-----------------------------
int getMaxvalue(int a, int b){
    return a > b ? a:b;
}

int getHeight(pTree tree){
    if(tree){
        int leftHeight = getHeight(tree->left); 
        int rightHeight = getHeight(tree->right); 
        return (leftHeight > rightHeight ? leftHeight:rightHeight)+1;
    }
    return 0;
}

pTree singleLeftRotation(pTree A){
    pTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->treeHeight = getMaxvalue(getHeight(A->left), getHeight(A->right)) + 1;
    B->treeHeight = getMaxvalue(getHeight(B->left), A->treeHeight) + 1;
    return B;
} 

pTree singleRightRotation(pTree A){
    pTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->treeHeight = getMaxvalue(getHeight(A->left), getHeight(A->right)) + 1;
    B->treeHeight = getMaxvalue(getHeight(B->right), A->treeHeight) + 1;
    return B;
}

pTree doubleLeftRotation(pTree A){
    A->left = singleRightRotation(A->left);
    return singleLeftRotation(A);
}

pTree doubleRightRotation(pTree A){
    A->right = singleLeftRotation(A->right);
    return singleRightRotation(A);
}

pTree AVLinsert(pTree tree, elementType ele){
    if(!tree){
        tree = (pTree)malloc(sizeof(tre));
        tree->element = ele;
        tree->left = tree->right = NULL;
        tree->treeHeight = 0;
    }
    else{
        if(ele < tree->element){
            tree->left = AVLinsert(tree->left, ele);
            if(getHeight(tree->left) - getHeight(tree->right) == 2){
                if(ele < tree->left->element)
                    tree = singleLeftRotation(tree);
                else
                    tree = doubleLeftRotation(tree);
            }
        }
        else if(ele > tree->element){
            tree->right = AVLinsert(tree->right, ele);
            if(getHeight(tree->right) - getHeight(tree->left) == 2){
                if(ele > tree->right->element)
                    tree = singleRightRotation(tree);
                else
                    tree = doubleRightRotation(tree);
            }
        }
        else tree->treeHeight = getMaxvalue(getHeight(tree->left), getHeight(tree->right)) + 1;
    }
    return tree;
}

int main(){
    printf("\n==========普通插入=====================================\n");
    int findElement = 33;
    int deleteData = 41;
    pTree tree=insert(NULL,30);
    tree=insert(tree,15);
    tree=insert(tree,41);
    tree=insert(tree,33);
    tree=insert(tree,50);
    tree=insert(tree,35);
    preOrderTraversal(tree);
    printf("\n");
    printf("The find element is:%d,the result is %d \n",findElement,find(tree, findElement)->element);
    printf("The min element:%d\n",get_min_ele(tree)->element);
    printf("The max element:%d\n",get_max_ele(tree)->element);
//    printf("delete the elemet %d\n",deleteData);
//    pTree new_tree = delete_ele(tree,deleteData);
    printf("\nordinary tree preOrder\n");
    preOrderTraversal(tree);
    printf("\n");

    printf("\n==========AVL插入=====================================\n");

    pTree AVLTree=AVLinsert(NULL,30);
    preOrderTraversal(AVLTree);
    AVLTree=AVLinsert(AVLTree,15);
    preOrderTraversal(AVLTree);
    AVLTree=AVLinsert(AVLTree,41);
    preOrderTraversal(AVLTree);
    AVLTree=AVLinsert(AVLTree,33);
    preOrderTraversal(AVLTree);
    AVLTree=AVLinsert(AVLTree,50);
    preOrderTraversal(AVLTree);
    AVLTree=AVLinsert(AVLTree,35);
    preOrderTraversal(AVLTree);
    printf("\n");
    printf("\nAVL tree preOrder\n");
    preOrderTraversal(AVLTree);

    return 1;
}
