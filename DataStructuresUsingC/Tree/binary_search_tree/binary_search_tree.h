#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//struct for node
typedef struct binary_tree
{
    struct binary_tree *lchild;
    int data;
    struct binary_tree *rchild;
}NODE,*PNODE,**PPNODE;
PNODE createNode(int value);
void insertNode(PPNODE root,int value);
void inOrder(PNODE root);
void postOrder(PNODE root);
void preOrder(PNODE root);
int countNodes(PNODE root);
int countLeafNodes(PNODE root);
int searchNode(PNODE root,int value);
int maxElement(PNODE root);
int minElement(PNODE root);
int deleteNode(PPNODE root,int ivalue);