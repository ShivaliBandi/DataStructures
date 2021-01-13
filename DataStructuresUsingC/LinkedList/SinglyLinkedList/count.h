int count(NODE *head)
{
	
	int icnt=0;
	if(head==NULL)
		return 0;
	else
	{
		while(head!=NULL)
		{
			//printf("| %d |-->| %d | ",icnt,head->data);
			icnt++;
			head=head->next;
		}
		return icnt;
	}
	
	
}
