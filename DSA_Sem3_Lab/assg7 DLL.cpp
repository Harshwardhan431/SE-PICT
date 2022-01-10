/*
Name : Harshwardhan Atkare
Roll No : 21106

Write C++ program for storing binary number using doubly linked lists
Write functions:-
a)1's compute's and 2's complement
b)Add two binary numbers
*/

#include<iostream>
#include<stdio.h>
using namespace std;

class Node{
    public:
    Node* prev;
    Node* next;
    int data;
};

class DoublyLinkedList{
    private:
    Node* head;
    public:
    DoublyLinkedList();
    DoublyLinkedList(int a[],int n);
    ~DoublyLinkedList();
    int Length();
    void Display();
    void ReverseDisplay();
    void Insert(int index,int x);
    void TwoComplement();
    void OnesComplement();
    //void AddBinary(DoublyLinkedList d2);
    void AddBinary(DoublyLinkedList d2);
};

void DoublyLinkedList::AddBinary(DoublyLinkedList d2){
    Node *q=d2.head;
    Node *p=head;
    DoublyLinkedList d3;
    while (p->next->next!=nullptr)
    {
        p=p->next;
    }
    while (q->next->next!=nullptr)
    {
        q=q->next;
    }
    Node* carry=new Node;
    int c=0;
    carry->data=0;
    carry->next=NULL;
    carry->prev=NULL;
    int len=Length();
    while (len--)
    {
        if (carry->data==0 && p->data==0 && q->data==0){
        carry->data=0;
        d3.Insert(c,0);
        c++;
    }else if (carry->data==0 && p->data==0 && q->data==1){
        carry->data=0;
        d3.Insert(c,1);
        c++;
    }else if (carry->data==0 && p->data==1 && q->data==0){
        carry->data=0;
        d3.Insert(c,1);
        c++;
    }
    else if (carry->data==0 && p->data==1 && q->data==1){
        carry->data=1;
        d3.Insert(c,0);
        c++;
    }else if (carry->data==1 && p->data==0 && q->data==0){
         carry->data=0;
        d3.Insert(c,1);
        c++;
    }else if (carry->data==1 && p->data==0 && q->data==1){
        carry->data=1;
        d3.Insert(c,0);
        c++;
    }else if (carry->data==1 && p->data==1 && q->data==0){
        carry->data=1;
        d3.Insert(c,0);
        c++;
    }else if (carry->data==1 && p->data==1 && q->data==1){
        carry->data=1;
        d3.Insert(c,1);
        c++;
    }
    p=p->prev;
    q=q->prev;
    }
    if (carry->data==1){
        d3.Insert(c,1);
    }
    cout<<"The binary addtion of both the strings is "<<endl;
    d3.ReverseDisplay();
}

void DoublyLinkedList::OnesComplement(){
     Node* p=head;
    while (p->next!=nullptr)
    {
        if (p->data==0)p->data=1;
        else p->data=0;
        p=p->next;   
        if (p->next->next==nullptr){
            break;
        }
    }
    if (p->data==1)p->data=0;
    else p->data=1;
}

void DoublyLinkedList::TwoComplement(){
    OnesComplement();
     Node* p=head;
    while (p->next!=nullptr)
    {
        p=p->next;   
        if (p->next->next==nullptr){
            break;
        }
    }
    bool f=false;
    if (p->data==0){
        p->data=1;
    }else{
        p->data=0;
        while (p!=head)
        {
            if (p->prev->data==0){
            p->prev->data=1;
            f=true;
            break;
            }else{
                p->prev->data=0;
               p=p->prev;
            }
        }
        
    }
    if (f==false){
        //Add new node at front
        Insert(0,1);
    }

}


DoublyLinkedList::DoublyLinkedList(){
    head=new Node;
    head->prev=nullptr;
    head->next=nullptr;
    head->data=0;
}

DoublyLinkedList::DoublyLinkedList(int *a,int n){
    head=new Node;
    head->prev=nullptr;
    head->data=a[0];
    head->next=nullptr;
    Node* tail=head;
    
    for(int i=1;i<n;i++){
        Node* t=new Node;
        t->prev=tail;
        t->data=a[i];
        t->next=tail->next;
        tail->next=t;
        tail=t;
    }
}

void DoublyLinkedList::Display(){
    Node* p=head;
    while (p->next!=nullptr)
    {
        cout<<p->data;
        p=p->next;
        if (p!=nullptr){
            //cout<<"<->"<<flush;
        }
    }
    cout<<endl;
}

void DoublyLinkedList::ReverseDisplay(){
     Node* p=head;
    while (p->next->next!=nullptr)
    {
        //cout<<p->data;
        p=p->next;
    }
    while (p!=head)
    {
        cout<<p->data;
        p=p->prev;
    }
    cout<<p->data;
}

int DoublyLinkedList::Length(){
    int length=0;
    Node* p=head;
    while (p->next!=nullptr)
    {
    
        length++;
        p=p->next;
    }
    return length;
}

void DoublyLinkedList::Insert(int index, int x) {
 
    if (index < 0 || index > Length()){
        return;
    }
 
    Node* p = head;
    Node* t = new Node;
    t->data = x;
 
    if (index == 0){
        t->prev = nullptr;
        t->next = head;
        head->prev = t;
        head = t;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next){
            p->next->prev = t;
        }
        p->next = t;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* p = head;
    while (head){
        head = head->next;
        delete p;
        p = head;
    }
}

int main(){
    int n1;
    cout<<"Enter number of elements in 1st binary munber"<<endl;
    cin>>n1;
    int a1[n1];
    DoublyLinkedList d1;
    cout<<"Enter elements in 1st binary number"<<endl;
    for(int i=0;i<n1;i++){
        cout<<"Enter "<<i<<" th element "<<endl;
        cin>>a1[i];
        d1.Insert(i,a1[i]);
    }
    int n2;
    cout<<"Enter number of elements in 2nd binary munber"<<endl;
    cin>>n2;
    int a2[n2];
    DoublyLinkedList d2;
    cout<<"Enter elements in 2nd binary number"<<endl;
    for(int i=0;i<n2;i++){
        cout<<"Enter "<<i<<" th element "<<endl;
        cin>>a2[i];
        d2.Insert(i,a2[i]);
    }
    cout<<"Enter 1 for One's Complement"<<endl;
    cout<<"Enter 2 for Two's Complement"<<endl;
    cout<<"Enter 3 for Adding two binay number"<<endl;
    int choice;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    if (choice==1){
        d1.OnesComplement();
        cout<<"One's complement of the 1st binary number is "<<endl;
        d1.Display();
    }else if (choice==2){
        d1.TwoComplement();
        cout<<"Two's complement of the 1st binary number is "<<endl;
        d1.Display();
    }else if (choice==3){
        d1.AddBinary(d2);
    }else{
        cout<<"Enter between 1 , 2 , 3"<<endl;
    }

    return 0;
}