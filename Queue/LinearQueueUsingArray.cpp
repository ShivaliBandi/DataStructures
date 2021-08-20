

#include <iostream>
using namespace std;
//Queue class has implemention of linear queue using array
class Queue
{

    int MaxSize, *arr, rear, front;

public:
    Queue();               //default constructor
    ~Queue();              //destructor
    bool isFull();         //to check if queue is empty
    bool isEmpty();        //to check is queue is empty
    bool enqueue(int val); //insert value in queue
    void display();        //for displaying queue
    int dequeue();         //for deleting value from queue
};
//isFull function return true if queue is full and false if queue is not full
bool Queue::isFull()
{

    if (this->rear == MaxSize - 1)
        return true;
    else
        return false;
}
//isempty function returns true if queue is empty and returns false if queue is not enmpty
bool Queue::isEmpty()
{
    if (this->rear == -1 && this->front == -1 || (this->front == this->rear))
        return true;
    else
        return false;
}
//enqueue function returns true if element is inserted in queue and takes input parameter as element which has to be inserted in
//queue and returns false if queue is full and values cant be added
bool Queue::enqueue(int val)
{
    if (isFull())
        return false;
    else
    {
        arr[++rear] = val;
        return true;
    }
}
//display function displays queue
void Queue::display()
{
    if (isEmpty())
        cout << "Queue IS Empty\n";
    else
        for (int i = front + 1; i <= rear; i++)
            cout << arr[i] << " ";
    cout << endl;
}
//dequeue function is used to delete elements from queue and returns that deleted element it returns -1 if queue is empty and no value can be deleted
int Queue::dequeue()
{
    if (isEmpty())
        return -1;
    else
        return arr[++front];
}
//it is default constructor we have initialized everything here
Queue::Queue()
{

    this->MaxSize = 5;
    this->rear = -1;
    this->front = -1;
    this->arr = new int[MaxSize];
};

int main()
{
    Queue *queue = new Queue();
    if (queue->enqueue(1) == true)
        cout << "Value Inserted in queue successfully";
    else
        cout << "ERROR:Unable to insert element in queue due to queue overflow\n";
    if (queue->enqueue(2) == true)
        cout << "Value Inserted in queue successfully";
    else
        cout << "ERROR:Unable to insert element in queue due to queue overflow\n";
    if (queue->enqueue(3) == true)
        cout << "Value Inserted in queue successfully";
    else
        cout << "ERROR:Unable to insert element in queue due to queue overflow\n";
    queue->display();
    if (queue->enqueue(4) == true)
        cout << "Value Inserted in queue successfully";
    else
        cout << "ERROR:Unable to insert element in queue due to queue overflow\n";

    if (queue->enqueue(5) == true)
        cout << "Value Inserted in queue successfully";
    else
        cout << "ERROR:Unable to insert element in queue due to queue overflow\n";
    if (queue->enqueue(6) == true)
        cout << "Value Inserted in queue successfully";
    else
        cout << "ERROR:Unable to insert element in queue due to queue overflow\n";
    queue->display();
    int ival = queue->dequeue();
    if (ival == -1)
        cout << "ERROR:Unable to delete element from queue due to queue underflow\n";
    else
        cout << "Value that has been removed from queue is-->" << ival << endl;
    queue->display();
    ival = queue->dequeue();
    if (ival == -1)
        cout << "ERROR:Unable to delete element from queue due to queue underflow\n";
    else
        cout << "Value that has been removed from queue is-->" << ival << endl;
    queue->display();
    ival = queue->dequeue();
    if (ival == -1)
        cout << "ERROR:Unable to delete element from queue due to queue underflow\n";
    else
        cout << "Value that has been removed from queue is-->" << ival << endl;
    queue->display();
    ival = queue->dequeue();
    if (ival == -1)
        cout << "ERROR:Unable to delete element from queue due to queue underflow\n";
    else
        cout << "Value that has been removed from queue is-->" << ival << endl;

    queue->display();
    ival = queue->dequeue();
    if (ival == -1)
        cout << "ERROR:Unable to delete element from queue due to queue underflow\n";
    else
        cout << "Value that has been removed from queue is-->" << ival << endl;
    queue->display();
    ival = queue->dequeue();
    if (ival == -1)
        cout << "ERROR:Unable to delete element from queue due to queue underflow\n";
    else
        cout << "Value that has been removed from queue is-->" << ival << endl;
    queue->display();
    queue->display();
    return 0;
}