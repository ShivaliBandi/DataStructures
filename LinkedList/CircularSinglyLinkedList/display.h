//Display LinkedList
void display(struct node *first)
{
	struct node* temp = first;
	/*if(first == NULL)
	{
		printf("LinkedList is Empty...!!\n\n");
		return;
	}*/
	while(first -> next != temp)
	{
		printf("%d\t",first -> data);
		first = first -> next;
	}
	printf("%d\t",first -> data);
	printf("\n");
}


