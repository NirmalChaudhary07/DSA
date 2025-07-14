#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *q;
};

// void initialzie(struct Queue *Q)
// {
//     int n;
//     for(int i=0;i<=Q->size-1;i++)
//     {
//         cout<<"enter the value : ";
//         cin>>n;

//         Q->q[i]=n;
//         Q->rear++;
//     }

// }

void enqueue(Queue *Q,int x)
{
    if(Q->rear==Q->size-1)
    {
        cout<<"queue is full ";
    }
    else
    {
        Q->rear++;
        Q->q[Q->rear]=x;
    }
}

void display(struct Queue Q)
{
    for(int i=Q.front+1;i<=Q.size-1;i++)
    {
        cout<<Q.q[i]<<endl;
    }
}

void Delete(struct Queue *Q, int n)
{
    int i=0;
    if(Q->front==Q->rear)
{
    cout<<"queue is empty";
    return;
}
else
{
    while(i<n){
    Q->front++;
    Q->q[Q->front]=0;
    i++;
    }
}
}

int main()
{
    struct Queue Q;
    cout<<"enter the size of the array : ";
    cin>>Q.size;
    Q.front=Q.rear=-1;
    Q.q=(int *)malloc(Q.size*sizeof(int));

    // initialzie(&Q);
    enqueue(&Q,5);
    enqueue(&Q,10);
    enqueue(&Q,32);
    enqueue(&Q,53);
    enqueue(&Q,54);
    enqueue(&Q,21);
    Delete(&Q,2);
    display(Q);


}

