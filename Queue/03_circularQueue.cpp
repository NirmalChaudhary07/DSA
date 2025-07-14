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
    {   front=rear=0;
        size=n;
        q=new int[n];
    }
    void enqueue(int x);
    void dequeue();
    void display();
    // ~Queue() { delete[] q; } // Destructor to free allocated memory
    int getFront() { return front; }
    int getRear() { return rear; }
};

void Queue:: enqueue(int x)
{
     if((rear+1)%size==front)
     {
        cout<<"queue is full";
     }

     else{
        rear=(rear+1)%size;
        q[rear]=x;
     }
    
}

void Queue:: dequeue()
{
    if(front== rear)
    {
        cout<<"queue is empty ";
    }
    else{
        front = (front+1)%size; // Move front to the next position
        q[front]=0;
    }
}

void Queue:: display()
{
    for(int i=0 ;i<size;i++)
    {
        cout<<"  "<<q[i];
    }
}



int main(){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    
    q.display();

    cout<<endl<<"Front: "<<q.getFront()<<endl;
    cout<<"Rear: "<<q.getRear()<<endl;
}