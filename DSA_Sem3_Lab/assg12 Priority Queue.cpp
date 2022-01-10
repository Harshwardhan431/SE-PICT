/*
Name : Harshwardhan Atkare
Roll No : 21106
Write program to implement a priority queue in C++ using an inorder
list to store the items in the queue. Create a class that includes 
the data items (which should be template) and the priority (which should be int).
The inorder list should contain these objects, with operator <= overloaded so
that the items with highest priority appear at the beginning of the list 
(which will make it relatively easy to retrieve the highest item.)
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    int pri;
    Node *next;
};

class Queue
{
    Node *front=NULL;
    Node *rear=NULL;
    public:
    void Display();
    void enq_pir(int x,int por);
    int deq_pir();
};

void Queue::enq_pir(int x,int por)
{
    Node *t=new Node;
    if (t==NULL)cout<<"Queue is Full"<<endl;
    else{
        t->data=x;
        t->pri=por;
        if (front==NULL){
            t->next=NULL;
            front=rear=t;
        }
        else{
            Node *travel=front;
            Node *tail=travel;
            bool f=false;
            while (travel!=NULL)
            {
                if (travel->pri<t->pri){
                    if (travel==front){
                        t->next=front;
                        front=t;
                    }else if (travel==rear){
                        t->next=NULL;
                        rear->next=t;
                        rear=t;
                    }else{
                        t->next=tail->next;
                        tail->next=t;
                    }
                    f=true;
                    break;
                }else if (travel->pri==t->pri){
                    if (travel==front){
                        t->next=travel->next;
                        travel->next=t;
                    }else if (travel==rear)
                    {
                         t->next=NULL;
                        rear->next=t;
                        rear=t;
                    }else{
                        t->next=travel->next;
                        travel->next=t;
                    }
                    f=true;
                    break;
                }
                tail=travel;
                travel=travel->next;
            }
            if (f==false)
            {
                  t->next=NULL;
                        rear->next=t;
                        rear=t;
            }
            
        }
    }
}

int Queue::deq_pir()
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
        cout<<"Enter the pirority of "<<(i+1)<<" th element "<<endl;
        int y;cin>>y;
        q.enq_pir(x,y);
    }
   // q.deq_pir();
   q.Display();
    return 0;
}