void displayNthValueFromLast(NODE *head,int inum){
	NODE *ptr1=head;
	NODE *ptr2=head;
	int icount=1;
	while(ptr2!=NULL)
	{
		if(icount>inum)
			ptr1=ptr1->next;
		ptr2=ptr2->next;
		icount++;
	}
	printf("ELEMENT: %d",ptr1->data);

}

