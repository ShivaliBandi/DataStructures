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


