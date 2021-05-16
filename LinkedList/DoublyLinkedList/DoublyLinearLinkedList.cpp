#include<iostream>
using namespace std;
//structure of node for doublyLinkedList
class Node{
    public:
    Node *prev=NULL;
    char data='\0';
    Node *next=NULL;
};
class DoublyLinearLinkedList
{   
    //Characteristics 
    private:
    Node *head;
    
    //behaviour
    public:
    //default constructor
    DoublyLinearLinkedList();
    ~DoublyLinearLinkedList();
    void insertAtFirst(char);
    void insertAtLast(char);
    void insertAtPosition(int,char);
    void deleteAtLast();
    void deleteAtFirst();
    void deleteAtPosition(int);
    void deleteByValue(char);
    bool search(char);
    int  count();
    void displayForward();
    void displayBackward();

};
//function definitions
// default constructor
DoublyLinearLinkedList::DoublyLinearLinkedList()
{
    
    head=NULL;
}
//this function inserts element at first in linkedlist
void DoublyLinearLinkedList::insertAtFirst(char element)
{
    Node *newNode=new Node();
    newNode->data=element;
    //check if LinkedList empty
    if(head==NULL)
    {
        head=newNode;
    }//if LinkedList is not empty
    else
    {   
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}
//this function displays linkedList in forward manner
void DoublyLinearLinkedList::displayForward()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"Linked List Is Empty\n";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}
//this function displays LinkedList in reverse order
void DoublyLinearLinkedList::displayBackward()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"Linked List Is Empty\n";
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->prev;
        }
    }
}
//this function inserts element at the end of the linkedlist 
//it accepts element
void DoublyLinearLinkedList::insertAtLast(char element)
{   
   Node *newNode=new Node();
   Node *temp=head;
    newNode->data=element;
    //check if LinkedList empty
    if(head==NULL)
        head=newNode;
        
    else
    {   
       while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;

    }
}
//this function returns total number of count in linkedlist
int DoublyLinearLinkedList::count()
{
    Node *temp=head;
    int count=0;
    if(head==NULL)
    {
        cout<<"Linked List Is Empty\n";
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
    }
    return count;
}
void DoublyLinearLinkedList::insertAtPosition(int ipos,char element)
{
    //if  first position then call insert first
    if(ipos==1)
        insertAtFirst(element);
    else
    {
        //if position is greater than zero and less than total number of nodes
        if(ipos<=count() && ipos>0)
        {
            Node *temp=head;
            Node *newNode=new Node();
            newNode->data=element;
            while(ipos!=2)
            {  
                ipos--;
                temp=temp->next;
            }
            
           
            newNode->prev=temp;
            
            newNode->next=temp->next;
            temp->next=newNode;
            newNode->next->prev=newNode;
        }
        //if position is count plus one then it will call insert last
        else if(ipos==count()+1)
            insertAtLast(element);
        //invalid position
        else
        {
            cout<<"ERROR:INVALID POSITION\n";
        }
    }
}
bool DoublyLinearLinkedList::search(char element)
{
    Node *temp=head;
    while(temp!=NULL)
    {

        if(temp->data==element)
            return true;
        temp=temp->next;
    }
       
    return false;
}
void DoublyLinearLinkedList::deleteAtFirst()
{
    Node *temp=head;
    if(head==NULL)
    {
          cout<<"ERROR:EMPTY lINKEDlIST\n";
    }
    else if(head->next==NULL)
    {
        head=NULL;
        delete head;
    }
    else
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
  
    

}
void DoublyLinearLinkedList::deleteAtLast()
{
    
    
    if(head==NULL)
    {
        
        cout<<"ERROR:LINKEDLIST IS EMPTY\n";

    }
    else if(head->next==NULL)
    {
        head=NULL;
        delete head;
    }
       
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        Node *temp2=temp->prev;
        temp2->next=NULL;
        delete temp;
    }
}
void DoublyLinearLinkedList::deleteAtPosition(int ipos)
{
    
    
    if(head==NULL)
        cout<<"ERROR:LINKEDLIST IS EMPTY\n";
    else if(ipos==1)
        deleteAtFirst();
    else if(ipos==count())
        deleteAtLast();
    else if(ipos>=2 && ipos<count())
    {
        Node *temp=head;
        while(ipos!=2)
        {
            temp=temp->next;
            ipos--;
        }
            
        Node *temp1=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        delete temp1;
    }
    else
    {
       cout<<"ERROR INVALID POSITION\n";
    }
}
void DoublyLinearLinkedList::deleteByValue(char element)
{   int flag=0;
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"LINKED LIST IS EMPTY\n";
       // flag=0;

    }
        
    else if(temp->next==NULL)
    {
        if(temp->data==element)
        {
            head=NULL;
            delete head;
            flag=1;
        }
    }

    else
    {
        while( temp->next->data!=element || (temp->next->next!=NULL && temp->next!=NULL )    )
        {
            if(head->data==element)
            {
                Node *temp1=head;
                head=head->next;
                head->prev=NULL;
                delete temp1;
                flag=1;
                break;
            }
          
            else if(temp->next->data==element)
            {  
               Node *temp1=temp->next;
                temp->next=temp->next->next;
                temp->next->prev=temp;
                delete temp1; 
                flag=1;
                break;

            }
            temp=temp->next;
        }
        if(temp->next->data==element)
        {
            Node *temp1=temp->next;
            temp->next=NULL;
            delete temp1;
            flag=1;
        }

    }
    if(flag==0)
    cout<<"Element is not present please enter element which is present in linkedList\n";
    else
    cout<<"ELement deleted successfully\n";
   
}
//deallocating memory for linkedllist
DoublyLinearLinkedList::~DoublyLinearLinkedList()
{
    Node *temp=head;
cout<<temp<<" before head delete \n";

    while(head!=NULL)
    {
     cout<<temp<<" head in while loop\n";   
        head=head->next;
        delete temp;
        temp=head;
    }
    cout<<temp<<" head after deletion\n";
}
int main()
{
    DoublyLinearLinkedList *dobj=new DoublyLinearLinkedList();
    
    int i = 0 , cnt = 0 , pos = 0 , no = 0 ;
    char ele='\0';
	
		
	cout<<"**************Doubly Linear LinkedList**************\n\n";
	while(1)
	{
		cout<<"1.Inserting the element at FIRST position \n\n2.Inserting the element at ANY position \n\n3.Inserting the element at LAST position \n\n4.Count the elements\n\n5.Display the elements in reverse \n\n6.Delete the element POSITION wise\n\n7.Search\n\n8.Delete the element that you want to delete VALUE wise\n\n0.Exit\n";
		cout<<"\n9.display linked list in forward  manner\nEnter your choice :\n";
		cin>>no;
		
		switch(no)
		{
			case 1:
					cout<<"Enter the  character data :\n";
					cin>>ele;
					(*dobj).insertAtFirst(ele);
					break;
					
			case 2:
					cout<<"Enter the  character data and position\n";
					cin>>ele;
                    cin>>pos;
					dobj->insertAtPosition(pos,ele);
					break;
					
			case 3:
					cout<<"Enter the character data :\n";
					cin>>ele;
					dobj->insertAtLast(ele);
					break;
			
			case 4:
					
					cout<<"Number of Elements from the given linkedlist : "<<dobj->count()<<endl;
					break;
			
			case 5:
					
						cout<<"Elements from the given list in reverse position are :\n";
						dobj->displayBackward();
					
					break;
            case 9:
					
						cout<<"Elements from the given list  are :\n";
						dobj->displayForward();
					
					break;
				
			case 6:
					cout<<"Enter the pos :\n";
					cin>>pos;
					dobj->deleteAtPosition(pos);
					break;
					
			case 7:
					cout<<"Enter the no that you want to search :\n";
					cin>>ele;
					if(dobj->search(ele))
						cout<<ele<<" is found in the linked list...!!\n";
					else
						cout<<ele<<" is not present in the linked list..!!\n";
					break;
			
			case 8:
					cout<<"Enter the no that you want to delete :\n";
					cin>>ele;
					dobj->deleteByValue(ele);
					
					break;
					
			case 0:
					exit(0);
					
			default:
					printf("Wrong choice...!\n\n");
		}
	}

    delete dobj;
    //delete *dobj;
   // cout<<dobj<<"\n";
    
}

