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
    void display(int front);
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

void Queue:: display(int front)
{
    // for(int i=((front+1)+1)%size ;i<=rear;i++)
    // {
    //     cout<<"  "<<q[i];
    // }

    if((front+1)%size!=rear+1)
    {
        cout<<" "<<q[(front+1)%size];
        display((front + 1) % size);
    }
}

// void Queue::display(int front)
// {
//     // Base case: if queue is empty or we've reached the end
//     if (front == rear)
//         return;
    
//     // Print current element
//     cout << " " << q[(front + 1) % size];
    
//     // Recursive call for next element
//     display((front + 1) % size);
// }



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
    
    q.display(q.getFront());

    cout<<endl<<"Front: "<<q.getFront()<<endl;
    cout<<"Rear: "<<q.getRear()<<endl;
}