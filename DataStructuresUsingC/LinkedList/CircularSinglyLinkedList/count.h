int count(struct node *first)
{
	int cnt = 0;
	struct node* temp = first;
	while(first -> next != temp)
	{
		cnt++;
		first = first -> next;
	}
	cnt++;
	return cnt;
}
