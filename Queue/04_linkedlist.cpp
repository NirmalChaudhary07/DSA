#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct Queue{
    struct node * front;
    struct node * rear;
};

void enqueue(Queue *q,int x)
{
    struct node *t;
    t= (struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    {
        cout<<"queue is full ";
    }
    else{
        t->data= x;
        t->next= NULL;
        if(q->front==NULL)
        {
            q->front=q->rear=t;
        }
        else
        {
            q->rear->next=t;
            q->rear=t;
        }
    }

}   

void display(struct Queue *q)
{
    struct node * t = q->front;
    while(t!= NULL)
    {   
        cout<<t->data<<" ";
        t=t->next;
    }
}
int main()
{
    struct node n;
    struct Queue q;
    q.front=NULL;
    q.rear=NULL;

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    display(&q);

}