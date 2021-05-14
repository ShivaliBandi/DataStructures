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
