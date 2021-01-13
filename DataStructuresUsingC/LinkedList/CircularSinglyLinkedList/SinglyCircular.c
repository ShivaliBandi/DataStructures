//Singly Cicular Linked List

#include<SinglyCircular.h>

int main()
{
	int i = 0 , cnt = 0 , ele = 0 , pos = 0 , no = 0 ;
	
	struct node* head = NULL;
	
	printf("**************Singly Circular LinkedList**************\n\n");
	while(1)
	{
		printf("1.Inserting the element at FIRST position \n\n2.Inserting the element at ANY position \n\n3.Inserting the element at LAST position \n\n4.Count the elements\n\n5.Display the elements\n\n6.Delete the element POSITION wise\n\n7.Search\n\n8.Delete the element that you want to delete VALUE wise\n\n0.Exit\n");
		printf("\nEnter your choice :\n");
		scanf("%d",&no);
		
		switch(no)
		{
			case 1:
					printf("Enter the data :\n");
					scanf("%d",&ele);
					insertAtFirst(&head,ele);
					break;
					
			case 2:
					printf("Enter the data and position\n");
					scanf("%d %d",&ele,&pos);
					insertAtPos(&head,ele,pos);
					break;
					
			case 3:
					printf("Enter the data :\n");
					scanf("%d",&ele);
					insertAtLast(&head,ele);
					break;
			
			case 4:
					cnt = count(head);
					printf("Elements from the given linkedlist : %d\n",cnt);
					break;
			
			case 5:
					if(head == NULL)
						printf("LinkedList is empty..!!\n");
					else
					{
						printf("Elements from the given list are :\n");
						display(head);
					}
					break;
				
			case 6:
					printf("Enter the pos :\n");
					scanf("%d",&pos);
					deleteByPosition(&head,pos);
					break;
					
			case 7:
					printf("Enter the no that you want to search :\n");
					scanf("%d",&pos);
					if(Search(head,pos))
						printf("%d is found in the linked list...!!\n",pos);
					else
						printf("%d is not present in the linked list..!!\n",pos);
					break;
			
			case 8:
					printf("Enter the no that you want to delete :\n");
					scanf("%d",&pos);
					if(deleteByValue(&head,pos))
						printf("%d is deleted...!!\n",pos);
					else
						printf("%d is not present in the linked list..!!\n",pos);
					
					break;
					
			case 0:
					exit(0);
					
			default:
					printf("Wrong choice...!\n\n");
		}
	}
	return 0;
}
