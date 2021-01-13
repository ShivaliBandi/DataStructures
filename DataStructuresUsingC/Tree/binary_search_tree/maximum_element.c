#include"binary_search_tree.h"
int maxElement(PNODE root)
{
    if(root==NULL)
        return INT_MIN;
    else
        while(root->rchild!=NULL)
            root=root->rchild;
    
    return root->data;
    
}