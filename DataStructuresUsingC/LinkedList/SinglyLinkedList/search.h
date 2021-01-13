BOOL search(NODE *head,int key)
{
	int icount=1,flag=0;
	do
	{
		if(head->data==key)
		{
			
			flag=1;break;
		}
		
		else
		{
			head=head->next;
				
		}
		++icount;
		

	}while(head!=NULL);
	if(flag!=0)
		return icount;
	else 
		return 0;

}

