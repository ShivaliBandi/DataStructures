

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int BOOL;
typedef struct node
{
	int data;
	struct node* next;
}NODE;


NODE * getNode(int ivalue)
{
	NODE * newNode=(NODE *)malloc(sizeof(NODE));
	newNode->data=ivalue;
	newNode->next=NULL;
	return newNode;
}
void append(NODE **head,int ivalue)
{
	NODE * newNode=getNode(ivalue);
	NODE *temp=*head;
	if (*head==NULL)
		*head=newNode;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;

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
void detectLoop(NODE *head)
{
    NODE *slow=head;
    NODE *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast->next==slow)
        	break;
        
    }
    if(fast->next!=slow )
        printf("loop not detected\n");
    else
        printf("loop   detected\n");
    

}
int main(){

    NODE *head=NULL;
    append(&head,10);
    append(&head,20);
    append(&head,30);
    append(&head,40);
    append(&head,50);
  head->next->next->next->next->next=head->next;
   //display(head);
   detectLoop(head);
    return 0;
}
