/*
preOrder:this function displays data in LRD manner where LRD means
first it traverse left subtree  and then it traverse right subtree and then it prints data
OUTPUT:it displays tree post-order traversal rule
input:it takes input structure of root
*/
#include<binary_tree.h>

void preOrder(PNODE root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
        
    }
   

}