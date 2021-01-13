/*
postOrder:this function displays data in DLR manner where LDR means
first it prints data  and it traverse left subtree  and then it traverse right subtree and then 
OUTPUT:it displays tree post-order traversal rule
input:it takes input structure of root
*/
#include"binary_tree.h"
void postOrder(PNODE root)
{
    if(root!=NULL)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d  ",root->data);
    }
   

}