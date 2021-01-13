/*Delete elements by their value
bool deleteByValue(struct node** first , int val)
{
	struct node* temp = (*first) ,* t2 = NULL;
	if(Search((*first),val))
	{
		if(temp -> data == val)
		{
			t2 = (*first);
			(*first) = temp -> next;
			free(t2);
		}
		else
		{
			while(temp -> next != NULL && ((temp -> next) -> data != val))
			{
				temp = temp -> next;
			}
			if(temp -> next -> data == val)
			{
				t2 = temp -> next;
				temp -> next = temp -> next -> next;
				free(t2);
			}
		}
		return TRUE;
	}
	else
		return FALSE;
}
*/

//Delete elements by their value without using Search Function - TWO POINTER APPROACH 
bool deleteByValue(struct node** first , int val)
{
	struct node* temp1 = (*first) ,*temp2 = (*first)-> next ,*t2 = NULL;
	if(temp1 -> data == val)
	{
		t2 = (*first);
		printf("%p",(*first));
		(*first) = temp1 -> next;
		free(t2);
		printf("%p",(*first));
		return TRUE;	
	}
	else
	{
		while(temp2 != (*first))
		{
			if(temp2 -> data != val)
			{
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
			else
				break;
		}
		if(temp2 != (*first))
		{
			t2 = temp1 -> next;
			temp1 -> next = temp1 -> next -> next;
			free(t2);
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}	
}

