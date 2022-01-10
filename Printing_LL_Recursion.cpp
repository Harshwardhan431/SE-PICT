//Program to print ll using recursion

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
}*head=nullptr;

class LinkedList
{
    
    public:
    bool f=false;
    Node *pip=nullptr;
    void InsertAtEnd(int val);
    void Display(LinkedList *j,Node *p);
    void RDisplay(LinkedList *j,Node *p);
};


void LinkedList::RDisplay(LinkedList *j,Node *pi)
{ 
    if (pi!=nullptr){
        j->RDisplay(j,pi->next);
        cout<<pi->data<<" ";
    }
}
/*
void LinkedList::Display(LinkedList *j)
{  
    if (f==false){
        pip=head;
    }else{
        pip=pip->next;
    }
    if (pip!=nullptr){
        f=true;
         cout<<pip->data<<" ";
        j->Display(j);
    }
}*/

void LinkedList::Display(LinkedList *j,Node *pi)
{
    if (pi!=nullptr){
         cout<<pi->data<<" ";
        j->Display(j,pi->next);
       
    }
}
void LinkedList::InsertAtEnd(int val)
{
    Node *travel=head;
    Node *t=new Node;
    t->data=val;
    t->next=nullptr;
      if (head==nullptr){
        head=t;
    }
    else{
        while (travel->next!=nullptr)
        {
            travel=travel->next;   
        }
        travel->next=t;
    }
}

int main()
{
    LinkedList l;
     int n;
    cout<<"Enter how many elements you want to insert"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;l.InsertAtEnd(x);
    }
    l.Display(&l,head);
    return 0;
}

