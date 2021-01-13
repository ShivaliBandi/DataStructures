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
int reverseNum(NODE *head)
{
	int num=head->data,pw=10;
	do
	{	head=head->next;
		   num = num + (pw * head->data); 
		pw=pw*10;
		
	}while(head->next!=NULL);
	return num;
}

NODE * reverseAddition(NODE **head1,NODE **head2)
{
	NODE *result=NULL;
	
	int ivalue1=reverseNum(*head1);
	int ivalue2=reverseNum(*head2);
	int isum=ivalue1+ivalue2;
	while (isum != 0) 
    { 
     append(&result,(isum % 10)); 
     isum = isum/10; 
    }  
	return result;

}
void insertFirst(NODE **head,int ivalue)
{

	NODE *newNode=getNode(ivalue);
	NODE *temp=*head;
	newNode->next=temp;
	*head=newNode;
}
int count(NODE *head)
{
	
	int icnt=0;
	if(head==NULL)
		return 0;
	else
	{
		while(head!=NULL)
		{
			//printf("| %d |-->| %d | ",icnt,head->data);
			icnt++;
			head=head->next;
		}
		return icnt;
	}
	
	
}
BOOL search(NODE *head,int key)
{
	int icount=1,flag=0;
	do
	{
		if(head->data==key)
		{
			
			flag=1;break;
		}
		
		else
		{
			head=head->next;
				
		}
		++icount;
		

	}while(head!=NULL);
	if(flag!=0)
		return icount;
	else 
		return 0;

}




void insertAt(NODE **head,int ivalue,int ipos)
{
	NODE *temp=*head;
	NODE *newNode=getNode(ivalue);
	int icount=count(*head);
		if(ipos==1)
	jump:
			insertFirst(head,ivalue);
		else if(ipos<icount)
		{
			while(ipos!=2)
			{
				temp=temp->next;
				ipos--;
			}
			newNode->next=temp->next;
			temp->next=newNode;

		}
		else if(ipos==(icount+1))
			append(head,ivalue);
		else
		{
			printf("invalid position...\n please enter right psoition\n");
			scanf("%d",&ipos);
			goto jump;
		}
	

}
void deleteAtPos(NODE **head,int ipos)
{
	NODE *temp=*head;
	NODE *temp1=temp;
	int icount=count(*head);
	jump:
	if(*head==NULL)
		printf("linkedlist is empty\n");
	else
	{
		if(ipos==1)
		{
			*head=(*head)->next;
			free(temp);
			
		}
		else if(ipos>icount)
		{
			printf("invalid position...\n please enter right psoition\n");
			scanf("%d",&ipos);
			goto jump;
		}
		else 
		{
			while(ipos!=2)
			{
				temp=temp->next;
				ipos--;
			}
			temp1=temp->next;
			temp->next=temp->next->next;
			free(temp1);


		}
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
void deleteByValue(NODE **head,int ivalue)
{	//without search
	NODE *first,*second;
	
	jump:
	first=*head;
	second=(*head)->next;
//	temp=NULL;
	if(first->data==ivalue)
	{
		(*head)=(*head)->next;
		free(first);
		first=*head;

	}
	else
	{
		while(second!=NULL)
		{
			
			if(second->data!=ivalue)
			{
				first=first->next;
				second=second->next;
			}
			else break;

		}
		if(second!=NULL)
		{
			//temp=first->next;
			first->next=first->next->next;
			free(second);
		}
		else
		{
			printf("invalid value please enter valid value\n");
			scanf("%d",&ivalue);
			goto jump;
		}
	}
	
		/* using search function--->
		NODE *temp=*head;
		NODE *temp1=temp;
		int icount;
		jump:
			icount=search(*head,ivalue);
			if(icount==0)
			{
				printf("invalid value...\n please enter right value again\n");
				scanf("%d",&ivalue);
				goto jump;
			}
			else if(icount==1)
			{
				(*head)=(*head)->next;
				free(temp);
				temp=*head;
			}
			else
			{
				while(icount!=2)
				{
					temp=temp->next;
					icount--;
				}
				temp1=temp->next;
				temp->next=temp->next->next;
				free(temp1);
			}*/
		
}
void middleOfTheLinkedList(NODE *head)
{
	NODE *ptr1=head;
	NODE *ptr2=head;
	if(head==NULL)
	{
		printf("sorry LinkedList is empty");
	}
	else
	{
		while(ptr2->next!=NULL && ptr2->next->next!=NULL  )
		{
			ptr2=ptr2->next->next;
			ptr1=ptr1->next;
		}
		printf("Middle value is %d\n",ptr1->data);
	}
	
}

void displayNthValueFromLast(NODE *head,int inum){
	NODE *ptr1=head;
	NODE *ptr2=head;
	int icount=1;
	while(ptr2!=NULL)
	{
		if(icount>inum)
			ptr1=ptr1->next;
		ptr2=ptr2->next;
		icount++;
	}
	printf("ELEMENT: %d",ptr1->data);

}


int frequency(NODE *head,int key)
{
	int icount=0;
	do
	{
		if(head->data==key)
			icount++;
		head=head->next;

	}while(head!=NULL);
	
		return icount;

}
