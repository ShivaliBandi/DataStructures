void insertAtFirst(struct node** first , int val)
{
	struct node* newN = createNewnode(val), *temp = (*first);
	
	//If the linked list is empty 
	if(*first == NULL)
	{
		*first = newN;
		newN -> next = (*first);
	}
	else
	{
		while(temp -> next != (*first))
			temp = temp -> next;
		
		temp -> next = newN;
		newN -> next = (*first);
		(*first) = newN;
	}
	printf("Element inserted successfully...!!\n");
}

