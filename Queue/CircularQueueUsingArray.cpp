

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

    if ((this->rear == MaxSize - 1 && this->front == 0) || (this->rear + 1 == this->front))
        return true;
    else
        return false;
}
//isempty function returns true if queue is empty and returns false if queue is not enmpty
bool Queue::isEmpty()
{
    if (this->front == -1)
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
        if (isEmpty())
            front = 0;

        rear = (rear + 1) % MaxSize;
        arr[rear] = val;

        return true;
    }
}
//display function displays queue
void Queue::display()
{
    int i = 0;
    if (isEmpty())
    {
        cout << endl
             << "Empty Queue" << endl;
    }
    else
    {
        cout << "Front -> " << front;
        cout << endl
             << "Items -> ";
        for (i = front; i != rear; i = (i + 1) % MaxSize)
            cout << arr[i];
        cout << arr[i];
        cout << endl
             << "Rear -> " << rear;
    }
}
//dequeue function is used to delete elements from queue and returns that deleted element it returns -1 if queue is empty and no value can be deleted
int Queue::dequeue()
{
    int val = -1;
    if (isEmpty())
        return -1;
    else
    {
        if (rear == front)
        {

            front = -1;
            rear = -1;
        }
        else
        {

            front = (front + 1) % MaxSize;
        }
        val = arr[front];
        return val;
    }
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
    queue->display();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->enqueue(40);

    queue->enqueue(50);
    cout << "\nDEqueue--> " << queue->dequeue() << endl;
    queue->display();
    queue->display();
    queue->enqueue(60);
    queue->display();
    return 0;
}