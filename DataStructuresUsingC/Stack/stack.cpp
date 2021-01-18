#include <iostream>
#include <cstring>

using namespace std;

class Stack
{
  //Characteristics
  private:
      int arr[10], top;
  
  //Behaviour
  public:
      //Default constructor
      Stack();
      
      //Functions
      bool isEmpty();
      bool isFull();
      void push(int);
      int pop();
      int length();
};
void Stack::push(int ival)
{
  if(isFull()==true)
  {
    cout<<"unable to  push value stack is full\n";
    return;
  }
  arr[++top]=ival;
  cout<<"push successfull\n";
}
int Stack::pop()
{
  int ret=0;
  if(isEmpty()==true)
    return -1;
  else{
     ret=arr[top--];
  return ret;
  }
 
}
//Function definitions of Stack Class

//Default Constructor
Stack :: Stack()
{
  arr[10] = {0};
  top = -1;
}

//isEmpty function checks that given array is empty or not by using top variable.
//If stack is empty, then value of top is -1.
bool Stack :: isEmpty()
{
  if(top == -1)
    return true;
  else
    return false;
}

//isFull function checks that given array is full or not by using top variable.
//If stack is full, then value of top is equal to length of array minus 1.
bool Stack :: isFull()
{
  if(top >=11)
    return true;
  else
    return false;
}

//

//length function returns number of elements from stack.
int Stack :: length()
{
  int i = top, cnt = 0;
  
  while(i != -1)
  {
    cnt++;
    i--;
  }
  
  return cnt;
}


int main()
{
  Stack sobj;
  sobj.push(10);
  sobj.push(20);
  sobj.push(30);
  int ret=sobj.pop();
  if(ret==-1)
    cout<<"Unable to pop,stack is empty";
  else
    cout<<"Pop value is --> "<<ret<<endl;
  return 0;
}
