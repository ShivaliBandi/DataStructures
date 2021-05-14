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


