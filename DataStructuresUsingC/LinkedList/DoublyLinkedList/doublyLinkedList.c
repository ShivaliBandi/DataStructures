
#include"doublyLinkedList.h"

int main()
{	NODE * head=NULL;
	while(1)
	{
		int inum=0,ivalue;
		int ino=0;
		printf("please choose:\n1.append N nodes \n2.insert at LAST node\n3.insert at FIRST\n4.insert at ANY position\n5.DISPLAY\n");
		printf("6.search\n7.count total nodes\n8.delete a node by accepting a position\n9.delete a node by acccepting value\n10.exit\n");
		scanf("%d",&inum);
		switch(inum)
		{
			case 1:
				printf("Enter total number of nodes you want to append\n");
				scanf("%d",&ino);
				while(ino!=0)
				{
					scanf("%d",&ivalue);
					append(&head,ivalue);
					ino--;
				}
				break;
		    case 5:
				display(head);
				break;
			default:
				exit(0);


		}
	}
    return 0;
}

/*

	case 2:
				printf("\n******please enter a value*****\n");
				scanf("%d",&ivalue);
				append(&head,ivalue);
				break;
			case 3:
				printf("\n******please enter a value*****\n");
				scanf("%d",&ivalue);
				insertFirst(&head,ivalue);
				break;
			case 4:
				printf("\n******please enter a value and position*****\n");
				scanf("%d%d",&ivalue,&ino);
				insertAt(&head,ivalue,ino);
				break;
			
			case 6:

				printf("enter element you want to search\n");
				scanf("%d",&ivalue);
				if(search(head,ivalue))
					printf("element %d is present at %d position\n",ivalue,search(head,ivalue));
				else
					printf("element %d is not present in linkedlist\n",ivalue);
				break;
			case 7:
				if(count(head)==0)
					printf("Linkedlist is empty\n");
				else
					printf("total number of nodes in linkedlist---> %d\n",count(head));
				break;
			case 8:
				printf("enter position of node which you want to delete\n");
				scanf("%d",&ivalue);
				deleteAtPos(&head,ivalue);
				break;
			case 9:
				printf("enter element which you want to delete\n");
				scanf("%d",&ivalue);
				deleteByValue(&head,ivalue);
				break;

                */