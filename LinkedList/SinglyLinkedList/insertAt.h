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

