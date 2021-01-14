#include"binary_search_tree.h"
/*
countLeafNodes:this function print number of leaf nodes in tree
INPUT:this function take input a root of a tree
OUTPUT:this function return count of leaf node
*/
int countLeafNodes(PNODE root)
{
    if(root!=NULL)
    {
        if(root->lchild==NULL && root->rchild==NULL)
            return 1;
        return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);    
    }
}