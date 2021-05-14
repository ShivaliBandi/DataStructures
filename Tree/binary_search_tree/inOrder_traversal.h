#include<binary_tree.h>
/*
inOrder:this function displays data in LDR manner where LDR means
first it traverse left subtree then it prints data and then it traverse right subtree
OUTPUT:it displays tree in-order traversal rule
input:it takes input structure of root
*/
void inOrder(PNODE root)
{
    if(root!=NULL)
    {
        inOrder(root->lchild);
        printf("%d  ",root->data);
        inOrder(root->rchild);
    }
   

}