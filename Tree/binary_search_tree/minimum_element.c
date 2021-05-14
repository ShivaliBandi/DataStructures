#include"binary_search_tree.h"
int minElement(PNODE root)
{
    if(root==NULL)
        return INT_MAX;
    else
    {
        while(root->lchild!=NULL)
            root=root->lchild;
    }
    return root->data;
    
}