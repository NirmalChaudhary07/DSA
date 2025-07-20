#include<iostream>
using namespace std;

struct node{
    struct node * left;
    int data;
    struct node * right;
}*root=NULL;

struct Queue{
    int size;
    int front;
    int rear;
    node **Q;
};

void enqueue(struct Queue *q,struct node *p)
{
    if(((q->rear+1)%q->size) == q->front)
    {
        cout<<"queue is full ";
    }
    
    else{
       q->rear=(q->rear+1)%q->size;
       q->Q[q->rear]=p;
    }

}

node * dequeue(struct Queue *q)
{
    node * x =NULL;
    if(q->front== q->rear)
    {
        cout<<"queue is empty ";
    }
    else{
        q->front = (q->front+1)%q->size; // Move front to the next position
        x=q->Q[q->front];
        q->Q[q->front]=0;
    }
    return x;
}
void create(struct Queue *q)
{
    struct node *t,*p;
    int x;

    cout<<"enter the root node : ";
    cin>>x;
    root= (struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->left=root->right=NULL;
    enqueue(q,root);

    while(q->front!=q->rear)
    {
        p =dequeue(q);
        cout<<"enter left child "<<p->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            enqueue(q,t);
        }

        cout<<"enter right child "<<p->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            enqueue(q,t);
        }
    }
}

void preorder(struct node *p)
{
    if(p)
    {
        cout<<" "<<p->data;
        preorder(p->left);
        preorder(p->right);
    }
}
   
void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<" "<<p->data;
    }
}
int main()
{
    Queue q;
    cout<<"enter the queue size :";
    cin>>q.size;

    q.front=q.rear=-1;
    q.Q=(struct node **)malloc(q.size*sizeof(struct node));

    create(&q);
    preorder(root);
    postorder(root);
}