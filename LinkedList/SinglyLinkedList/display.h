void display(NODE *head)
{
	if(head==NULL)
		printf("linkedlist is empty\n");
	else
	{
	int icnt=1;
	while(head!=NULL)
	{
		printf("| %d |-->| %d | ",icnt,head->data);
		icnt++;
		head=head->next;
	}
	}	
	

}
