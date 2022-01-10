/*
Name : Harshwardhan Atkare
Roll No : 21106
Queues are frequently used in computer programming, and a typical 
example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs
are processed in the order they enter the system. Write C++ program 
for simulating job queue. Write functions to add job and delete job from queue. 
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class Queue
{
    Node *front=NULL;
    Node *rear=NULL;
    public:
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x)
{
    Node *t =new Node;
    if (t==NULL)cout<<"Queue is Full"<<endl;
    else{
        t->data=x;
        t->next=NULL;
        if (front==NULL)front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int Queue::dequeue()
{
    int x=-1;
    Node *p;
    if (front==NULL)cout<<"Queue is empty"<<endl;
    else{
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}

void Queue::Display()
{
    struct Node *p=front;
    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    Queue q;
    int n;
    cout<<"Enter the size of the queue"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the "<<(i+1)<<" th element to enqueue"<<endl;
        int x;cin>>x;
        q.enqueue(x);
    }
    q.dequeue();
    q.Display();
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    Node *t =new Node;
    if (t==NULL)cout<<"Queue is Full"<<endl;
    else{
        t->data=x;
        t->next=NULL;
        if (front==NULL)front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    Node *p;
    if (front==NULL)cout<<"Queue is empty"<<endl;
    else{
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p=front;
    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the queue"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the "<<(i+1)<<" th element to enqueue"<<endl;
        int x;cin>>x;
        enqueue(x);
    }

    dequeue();
    Display();
    return 0;
}*/