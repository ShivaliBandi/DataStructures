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

