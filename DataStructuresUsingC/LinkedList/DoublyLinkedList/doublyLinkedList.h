#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
    struct node* prev;
    int data;
    struct node* next;
}NODE;
NODE* getNode(int value)
{
    NODE * newNode=(NODE *)malloc(sizeof(NODE));
    newNode->prev=newNode->next=NULL;
    newNode->data=value;
    return newNode;
}
void append(NODE **head,int value)
{
    NODE  *newNode=getNode(value);
    NODE *temp=*head;
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void display(NODE *head)
{
	if(head==NULL)
		printf("linkedlist is empty\n");
	else
	{
        int icnt=1;
        while(head!=NULL)
        {
            printf("| %d |-->| %d | ",icnt,head->data);
            icnt++;
            head=head->next;
        }
	}	
}

