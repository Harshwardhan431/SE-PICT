#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class Node{
    char data;
    Node *next;
    public:
    Node()
    {
        data=0;
        next=NULL;
    }

    Node(int x)
    {
        data=x;
        next=NULL;
    }

    friend class Stack;
};

class Stack{
    private:
    Node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    void Push(char x);
    char pop();
    void Display();
    bool isEmpty();
    char getTop();
    int isBalance(char *exp);
};

char Stack::getTop()
{
    
    //if (top->next==nullptr)return 0;
    return top->data;
}

bool Stack::isEmpty()
{
    if (top->data==-1)return true;
    else return false;
}

void Stack::Push(char x)
{
    Node *t=new Node;
    if (t==NULL)
    {
        cout<<"Stack Overflow"<<endl;
    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
    cout<<"Top element after Pushing is "<<getTop()<<endl;
}

char Stack::pop(){
    Node *p;
    int x=-1;
    if (top==NULL)
    cout<<"UnderFlow"<<endl;
    else{
        p=top;
        top=top->next;
        x=p->data;
        delete p;
    }
    return x;
}

void Stack::Display()
{
    Node *p=top;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Stack::isBalance(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
           // cout<<"Pushing "<<getTop()<<endl;
            Push(exp[i]);
        }else{
            //cout<<"Poping "<<getTop()<<endl;
            if (exp[i]==')' && top->data=='('){
                pop();
            }else if (exp[i]=='}' && top->data=='{'){
                pop();
            }
            else if (exp[i]==']' && top->data=='['){
                pop();
            }
        }
    }
    if (top==NULL)return 1;
    else return 0;
}

int main()
{
    Stack s;
    int n;
    cin>>n;
    char *exp;
    exp=new char[n];
    cout<<"Enter the expersion"<<endl;
    cin>>exp;
    cout<<s.isBalance(exp);
    return 0;
}