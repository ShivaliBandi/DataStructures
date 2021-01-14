/*
insertNode:this function inserts value into binary tree,while inserting it checks whether the given value 
is greater than current pointing data or less then than that
If the value is greater than current pointing data then it will insert on right child
if the value is less than current pointing data then it will insert on left child
and is data is same then it wont insert because we dont insert duplicate element
OUTPUT:it doesnt return anything
INPUT:address of root and integer value
*/
#include"binary_search_tree.h"
//createNode:this function  creates a new node 
//OUTPUT: return pointer of new node 
// input:integer value
PNODE createNode(int value)
{
    PNODE newNode=(PNODE)malloc(sizeof(NODE));
    newNode->data=value;
    newNode->lchild=newNode->rchild=NULL;
    //printf("data-->%d\n",newNode->data);
    return newNode;
}

void insertNode(PPNODE root,int value)
{
    PNODE newNode=createNode(value);
    PNODE temp=*root;
    if(*root==NULL)
    {
        *root=newNode;
    }
    else
    {
      while(1)
      {
          if(temp->data==value)
          {
              free(newNode);
              break;
          }
          else if(temp->data>value)
          {
              if(temp->lchild==NULL)
              {
                  temp->lchild=newNode;
                  break;
              }
              else
                temp=temp->lchild;
          }
          else 
          {
              if(temp->rchild==NULL)
              {
                  temp->rchild=newNode;
                  break;
              }
              else
                temp=temp->rchild;
          }
      }  
    }
    
    

}
