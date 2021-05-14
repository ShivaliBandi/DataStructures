/*
countNodes:this function tell us total number of nodes in tree
intput:it takes input root of tree that is starting point of tree
outPut :this function return total number of nodes
*/
#include"binary_tree.h"
int countNodes(PNODE root)
{
    static int icnt=0;
    if(root!=NULL)
    {
        icnt++;
        //printf("%d  ",root->data);
        countNodes(root->lchild);
        countNodes(root->rchild);
        
    }
    return icnt;
   

}