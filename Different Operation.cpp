/*Write c++ fumction to create linkedlist of each character in given string.
If charater is in lower case insert at start ,if charater is in upper
case insert at the end.Perform following operations
1)Accept string and create list as said above.
2)After every vowel enter new node with # as data.
3)Delete all consonats in upper case.*/

//ackermann function
//graphs
//m3
//ll question
//cp

#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        char data;
        Node *next;
};

class LinkedList
{
    Node *head=nullptr;
    public:
    void InsertAtEnd(char val);
    void InsertAtBegVov(char val);
    void InsertAtEndVov(char val);
    void Display();
    void InsertAtBeg(char val);
    void Delete(int index);
};

void LinkedList::Delete(int index)
{
    if (index==1){
         if (head->next==nullptr){
        delete head;
    }else{
        Node *p=head;
        head=head->next;
        delete p;
    }
    }else{
        Node *front=head;
    Node *p;
    while (front->next!=nullptr)
    {
        p=front;
        front=front->next;
    }
    p->next=nullptr;
    delete front;
    }
}

void LinkedList::InsertAtBegVov(char val)
{
    Node* t=new Node;
    t->data=val;
    if (val=='a' || val=='e' || val=='i' || val=='o' || val=='u'
    || val=='A' || val=='E' || val=='I' || val=='O' || val=='U'){
        Node *k=new Node;
        k->data='#';
        if (head==nullptr){
            k->next=nullptr;
        t->next=k;
        head=t;
        }else{
            k->next=head;
            head=k;
            t->next=head;
            head=t;
        }
    }else{
        InsertAtBeg(val);
    }
}

void LinkedList::InsertAtEndVov(char val)
{
    Node *travel=head;
    Node *t=new Node;
    t->data=val;
    if (val=='a' || val=='e' || val=='i' || val=='o' || val=='u'
    || val=='A' || val=='E' || val=='I' || val=='O' || val=='U'){
         Node *k=new Node;
        k->data='#';
        k->next=nullptr;
        if (head==nullptr){
        t->next=k;
        head=t;
        }else{
            while (travel->next!=nullptr)
            {
                 travel=travel->next;
            }
            t->next=k;
            travel->next=t;

        }
    }else{
        InsertAtEnd(val);
    }
}

void LinkedList::Display()
{
    Node *p=head;
    if (head==nullptr){
        cout<<"Empty list"<<endl;
        return;
    }
    while (p!=nullptr)
    {
        cout<<p->data;
        p=p->next;
    }
}

void LinkedList::InsertAtBeg(char val)
{
    Node* t=new Node;
    t->data=val;
       if (head==nullptr){
        t->next=nullptr;
        head=t;
    }else{
        t->next=head;
        head=t;
    }
}

void LinkedList::InsertAtEnd(char val)
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
    int choice=1;
     int n;
    cout<<"Enter how many elements you want to insert"<<endl;
    cin>>n;
    while (choice)
    {
    cout<<"Enter 1 for Accept string and create list as for lower case insert at begin and for upper insert at last"<<endl;
    cout<<"Enter 2 for After every vowel enter new node with # as data."<<endl;
    cout<<"Enter 3 for Delete all consonats in upper case"<<endl;
    cout<<"Enter 4 for displing list"<<endl;
    cout<<"Enter 5 for clearing list"<<endl;
    cout<<"Enter 6 to exit"<<endl;
    cin>>choice;
    if (choice==1)
    {
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the "<<(i+1)<<" th character "<<endl;
        char x;cin>>x;
        if (int(x)>96){
            l.InsertAtBeg(x);
        }else{
            l.InsertAtEnd(x);
        }
    }

    }else if (choice==2)
    {
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the "<<(i+1)<<" th character "<<endl;
        char x;cin>>x;
        if (int(x)>96){
            l.InsertAtBegVov(x);
        }else{
            l.InsertAtEndVov(x);
        }
    }
    }else if (choice==3)
    {
        for(int i=1;i<=n;i++)
    {
        cout<<"Enter the "<<(i)<<" th character "<<endl;
        char val;cin>>val;
        l.InsertAtEnd(val);
        if ( val=='A' || val=='E' || val=='I' || val=='O' || val=='U'){
    }else{
        l.Delete(i);
    }
    }
    }
    else if (choice==4)
    {
        l.Display();
        cout<<endl;
    }else if (choice==5){
        for(int i=1;i<=n;i++)
        {
            l.Delete(i);

        }
    }else if (choice==6){break;}
    }
    return 0;
}
