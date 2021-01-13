//implementation of binary search tree in c
#include"binary_search_tree.h"
//#include"countNodes.h"
#include<limits.h>
int main()
{
    PNODE root=NULL;
    while(1)
	{
		int inum=0,ivalue;
		int ino=0;
		printf("please choose:\n1.insert a value in tree \n2.display tree in In-Order trasversal\n3.display tree in Post-Order traversal\n4.display tree in Pre-Order traversal\n");
		printf("5.Count Number Of Nodes\n6.Count Number Of Leaf Node\n7.search  node in tree\n8.Maximun element from given tree\n9.Minimmum elememnt from given tree\n");
		printf("10.delete node\n");
        scanf("%d",&inum);
		switch(inum)
		{
			case 1:
                printf("Enter value\n");
                scanf("%d",&ivalue);
                insertNode(&root,ivalue);
                break;
            case 7:
                printf("Enter value\n");
                scanf("%d",&ivalue);
                inum=searchNode(root,ivalue);
                if(inum==0)
                    printf("element not exists\n");
                else if(inum==2)
                    printf("Tree is empty\n");
                else 
                    printf("element exists\n");
                break;
            case 2:
                printf("Display tree in In-Order traversal\n");
                inOrder(root);
                break;
            case 3:
                printf("Display tree in Post-Order traversal\n");
                postOrder(root);
                break;
            case 4:
                printf("Display tree in Pre-Order traversal\n");
                preOrder(root);
                break;
            case 5:
                printf("Count Number Of Nodes In Tree\t%d\n",countNodes(root));
                break;
            case 8:
                if(maxElement(root)==(-2147483648))
            	printf("Maximum element from tree is %d\n",maxElement(root));
                else
                    printf("Tree is empty\n");
            	break;
           case 9:
                if(minElement(root)==(2147483647))
            	    printf("Minimum element from tree is %d\n",minElement(root));
                else
                    printf("Tree is empty\n");
            	break;
            case 10:
                printf("enter value that you want to delete from the tree\n");
                scanf("%d",&inum);
                ivalue=deleteNode(&root,inum);
                if(ivalue==-1)
                    printf("Tree is empty\n");
                else
                    printf("deletion successfull\n");
                break;
                
			default:
				exit(0);


		}
    }
    return 0;
}
/*
countNodes:this function tell us total number of nodes in tree
intput:it takes input root of tree that is starting point of tree
outPut :this function return total number of nodes
*/

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
void postOrder(PNODE root)
{
    if(root!=NULL)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d  ",root->data);
    }
   

}
void preOrder(PNODE root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
        
    }
   

}
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
int maxElement(PNODE root)
{
    if(root==NULL)
        return INT_MIN;
    else
        while(root->rchild!=NULL)
            root=root->rchild;
    
    return root->data;
    
}
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
int deleteNode(PPNODE root,int ivalue)
{
    PNODE temp=*root;
    PNODE temp1=temp;
    if(root==NULL)
        return -1;
    else
    {
        while(1)
        {
            printf("one \n");
            if(temp->lchild->lchild!=NULL && temp->lchild->data<ivalue  )
                temp=temp->lchild;
            else if(temp->rchild->rchild!=NULL && temp->rchild->data>ivalue )
                temp=temp->rchild;
            else
            {
                            printf("two \n");

                if(temp->rchild->rchild==NULL && temp->lchild->lchild==NULL)
                {
                                printf("three \n");

                    if(temp->rchild->data==ivalue)
                    {
                                    printf("four \n");

                        temp1=temp->rchild;
                        temp->rchild=NULL;
                        free(temp1);
                        //return 1;
                        break;
                    }
                    else
                    {
                                    printf("five \n");

                        temp1=temp->rchild;
                        temp->rchild=NULL;
                        free(temp1);
                        //return 1;
                        break;
                    }
                }
            }
            

        }
    }
    return 1;
}