#include<iostream>
using namespace std;

class Queue{
    private:
    int size;
    int front;
    int rear;
    int *q;

    public:

    Queue(int n)
    {   front=rear=-1;
        size=n;
        q=new int[n];
    }
    void enqueue(int x);
    void dequeue();
    void display();

    ~Queue() { delete[] q; } // Destructor to free allocated memory
    int getFront() { return front; }
    int getRear() { return rear; }
};

void Queue :: enqueue(int x)
{
    if(rear==size-1)
    {
        cout<<"queue is full ";
    }
    else
    {
        rear++;
        q[rear]=x;
    }
}

void Queue:: dequeue()
{
    if(front==rear)
    {
        cout<<"queue is empty ";
    }
    else{
        front++;
        q[front]=0;
    }
}

void Queue:: display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<" "<<q[i];
    }
}

int main()
{
    Queue q(7);
    q.enqueue(4);
    q.enqueue(32);
    q.enqueue(5);
    q.enqueue(31);
   


    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.display();

    
}