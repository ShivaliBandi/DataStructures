void insertFirst(NODE **head,int ivalue)
{

	NODE *newNode=getNode(ivalue);
	NODE *temp=*head;
	newNode->next=temp;
	*head=newNode;
}


