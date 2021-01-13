//Search element from linked list
bool Search(struct node* first, int val)
{
	struct node* temp = first;
	do
	{
		if(first-> data == val)
		{
			return TRUE;
		}
		first = first -> next;
		
	}
	while(first != temp);
	return FALSE;
}


