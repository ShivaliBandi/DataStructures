void deleteByPosition(struct node** first, int pos)
{
	struct node* temp = (*first) , *t2 = NULL;
	int cnt = count(*first), i = 1;
	//If the linked list is empty
	if(*first == NULL)
	{
		printf("LinkedList is Empty...!\n");
	}
	else
	{
		//Delete the first element
		if(pos == 1)
		{
			while(temp -> next != (*first))
				temp = temp -> next;
			
			temp -> next = (*first) -> next;
			temp = (*first);
			(*first) = temp -> next;
			free(temp);
			printf("Node Deleted Successfully..!!\n");
		}
		//delete the last element
		else if(pos == cnt)
		{
			while(i != (pos-1))
			{
				i++;
				temp = temp -> next;
			}
			t2 = temp -> next;
			temp -> next = temp -> next -> next;
			free(t2);
			printf("Node Deleted Successfully..!!\n");
		}
		//delete the particular element
		else if(pos > 1 && pos < cnt)
		{
			while(i != (pos-1))
			{
				i++;
				temp = temp -> next;
			}
			t2 = temp -> next;
			temp -> next = t2 -> next;
			free(t2);
			printf("Node Deleted Successfully..!!\n");
		}
		else
		{
			printf("Wrong POSITION....!!\n");
		}
	}
}


