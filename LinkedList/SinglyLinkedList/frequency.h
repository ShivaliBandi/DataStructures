int frequency(NODE *head,int key)
{
	int icount=0;
	do
	{
		if(head->data==key)
			icount++;
		head=head->next;

	}while(head!=NULL);
	
		return icount;

}
