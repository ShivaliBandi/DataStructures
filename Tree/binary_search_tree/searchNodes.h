/*
searchNodes:this function searches the key in tree 
input:this function takes input root of tree and a key which we want to find in tree
output:it returns flag which tells us wheter the key is present or not
*/
#include"binary_search_tree.h"
int searchNode(PNODE root,int value)
{
   int iflag=-1;
    if(root==NULL)
    {
        printf("Tree is empty\n");
        iflag=2;

    }
    else
    {
      while(1)
      {
          if(root->data==value)
          { 
              iflag=1;
              break;
          }
          else if(root->lchild==NULL && root->rchild==NULL)
          {
              iflag=0;
              break;
              
          }
          else if(root->data>value)
          {
              if(root->lchild!=NULL)
              {
                root=root->lchild;
            
              }
          }
          else
          {
              if(root->rchild!=NULL)
              {
                root=root->rchild;                 
              }
                
          }
      } 
    }
    return iflag;
}