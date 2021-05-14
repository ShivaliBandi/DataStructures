//A stack is an ordered data structure in which insertion and deletion done at one end, called top.
//Implementation of stack data structure using Linked List.

#include <iostream>

using namespace std;

class Node
{
  public:
      int data;
      Node *next;
};

class Stack
{
  //Characteristics
  private :
      Node *head;
  
  //Behaviour
  public:
      Node *top;
      //Default constructor
      Stack();
      
      //Destructor
      ~Stack();
      
      //Functions
      bool isEmpty();
      void push(int);
      int pop();
      int length();
      void display();
};

//Function definitions of Stack Class
//Default Constructor
Stack :: Stack()
{
  head = NULL;
  top = NULL;
}

//Destructor
Stack :: ~Stack()
{
  Node *temp1 = top, *temp2 = NULL;
  
  while(temp1 -> next != NULL)
  {
    temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;
    delete temp2;
  }
  
  delete temp1;
}

//isEmpty function checks that given stack is empty or not by using top pointer.
//If stack is empty, then value of top is NULL.
bool Stack :: isEmpty()
{
  if(top == NULL)
    return true;
  else
    return false;
}

//push function push the value in stack if stack is not overflow.
void Stack :: push(int val)
{
  //Creating a new node.
  Node* newNode = new Node();
    newNode -> data = val;
    newNode -> next = top;
    
    //Setting top at that node.
    top = newNode;
    
  cout << val << " inserted successfully..!\n\n";
}

//pop function removes the value from top if the stack is not underflow.
int Stack :: pop()
{
  //Checking that stack is not empty.
  if(isEmpty() == true)
  {
    cout << "Stack is underflow now. You can't pop the value.\n";
    return 0;
  }
  
  //Creating a temp node.
  Node* temp = new Node();
  temp = top;
  int val = temp -> data;
  top = top -> next;
  
  //Deleting top value which is stored in temp node.
  delete temp;
  
  return val;
}

//length function returns number of elements from stack.
int Stack :: length()
{
  Node *temp = top;
  int cnt = 0;
  
  //Iterate until temp is not equal to NULL.
  while(temp != NULL)
  {
    cnt++;
    temp = temp -> next;
  }
  
  return cnt;
}

//display function prints the elements from stack.
void Stack :: display()
{
  Node *temp = top;
  
  cout << "Values From Top to Bottom\n\n";
  while(temp != NULL)
  {
    cout << temp -> data << endl;
    cout << "  " << endl;
    temp = temp -> next;
    //cout << cnt << " " << i << endl;
  }

}


//Entry point function.
int main()
{
  //Creating the object of Stack class.
  Stack *sobj = new Stack();
  
  cout << "********** Stack Data Structure **********\n\n";
  
  cout << "Initially top is : " << sobj->top << "\n\n";
  sobj -> push(10);
  sobj -> push(20);
  cout << "Top after pushing some values in stack : " << sobj->top << "\n\n";
  cout << "Top->data after pushing some values in stack : " << sobj->top->data << "\n\n";
  cout << "Length of stack before pop : " << (*sobj).length() << "\n\n";
  cout << "Value which is popped : " << sobj->pop() << "\n\n";
  cout << "Length of stack after pop : " << (*sobj).length() << "\n\n";
  sobj -> push(30);
  sobj -> push(40);
  sobj -> push(50);
  cout << "Final value of top : " << sobj->top << "\n\n";
  cout << "Final Length of stack : " << (*sobj).length() << "\n\n";
  sobj -> display();

  return 0;
}
