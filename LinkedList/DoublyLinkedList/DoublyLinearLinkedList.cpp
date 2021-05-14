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
    }
    else
    {   
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}
//this function displays linkedList
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
int main()
{
    DoublyLinearLinkedList *dobj=new DoublyLinearLinkedList();
    
     (*dobj).insertAtLast('d');
    (*dobj).insertAtLast('e');
    (*dobj).insertAtLast('f');
    (*dobj).insertAtPosition(3,'j');
    (*dobj).insertAtPosition(2,'k');
    cout<<"\n"<<dobj->count()<<"\n";
 
    cout<<"Display Forward\n";
    dobj->displayForward();
     dobj->deleteAtPosition(5);
   // dobj->deleteAtLast();
  //  (*dobj).insertAtPosition(1,'p');
    cout<<"\nDisplay Forward\n";
    dobj->displayForward();
     
  
    cout<<"\n"<<dobj->count()<<"\n"<<endl;
}

