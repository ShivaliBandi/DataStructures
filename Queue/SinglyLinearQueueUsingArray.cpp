#include<iostream>
using namespace std;
class Queue
{
    //characteristics
    private:
       
        int queue[10],front,rear,capacity;
    //behaviour
    public:
    Queue();
    int enQueue(int value);
    int deQueue();
    int isEmpty();
    int isFull();
    void displayQueue();

};
Queue::Queue()
{
    capacity=5;
    front=-1;
    rear=-1;
    queue[0]={0};

}
int Queue::isEmpty()
{
    if(front==-1)
        return 1;
    else return 0;
}
int Queue::isFull()
{
    if(rear==capacity-1)
        return 1;
    else 
        return 0;
}
int Queue::enQueue(int value)
{
    if(isFull()==1)
    {
        return 0;
    }
    else
    {
        if(isEmpty()==1)
        {
            front=0;
            queue[++rear]=value;

        }
        else
            queue[++rear]=value;
        return 1;
    }

}
int Queue::deQueue()
{
    if(isEmpty()==1)
    {
        return -1;
    }
    else
    {
        int ivalue=queue[front];
        for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            rear--
        
        return ivalue;
    }
}
void Queue::displayQueue()
{
    if(isEmpty()==1)
    {
        cout<<"ERROR:QUEUE IS EMPTY"<<endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
            cout<<queue[i]<<" ";
        cout<<"\n";
    }
}

int main()
{
    Queue *qobj=new Queue();
    int iret;
     qobj->displayQueue();
     iret=qobj->deQueue();
    if(iret!=-1)
        cout<<"value deleted successfully from queue value="<<iret<<endl;
    else
        cout<<"QUEUE IS UNDERLOW SO VALUE CANT BE deleted"<<endl;
     iret=qobj->enQueue(10);
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
    iret=qobj->enQueue(20);
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
     iret=qobj->enQueue(30);
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
     iret=qobj->enQueue(40);
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
     iret=qobj->enQueue(50);
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
     iret=qobj->enQueue(60);
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
    iret=qobj->enQueue(70);
    
    if(iret==1)
        cout<<"value inserted successfully in queue\n";
    else
        cout<<"QUEUE IS OVERFLOW SO VALUE CANT BE Inserted"<<endl;
    qobj->displayQueue();
    iret=qobj->deQueue();
    if(iret!=-1)
        cout<<"value deleted successfully from queue value="<<iret<<endl;
    else
        cout<<"QUEUE IS UNDERLOW SO VALUE CANT BE deleted"<<endl;
    qobj->displayQueue();
}