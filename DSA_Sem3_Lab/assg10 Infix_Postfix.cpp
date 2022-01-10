/*
Implement C++ program for expression conversion as infix to postfix
 and its evaluation using stack based on given conditions: 
	1. Operands and operator, both must be single character. 
	2. Input Postfix expression must be in a desired format. 
	3. Only '+', '-', '*' and '/ ' operators are expected. 
*/

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
    friend class Conversion;
};

class Conversion{
    private:
    Node *top=NULL;
    public:
    void Push(char x);
    char pop();
    void Display();
    int per(char x);
    int isOperand(char x);
    char *InToPost(char *infix);
};

void Conversion::Push(char x)
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
}

char Conversion::pop()
{
    struct Node *p;
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

void Conversion::Display()
{
    struct Node *p=top;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Conversion::per(char x)
{
    if(x=='+' || x=='-')
    return 1;
   else if(x=='*' || x=='/')
    return 2;
  return 0;
}

int Conversion::isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
      return 0;
    else
      return 1;
}

char* Conversion::InToPost(char *infix)
{
    int i=0,j=0;
   char *postfix;
   int len=strlen(infix);
   postfix=new char[len+2];
   while(infix[i]!='\0')
   {
      if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
      else
      {
        if(per(infix[i])>per(top->data))
          Push(infix[i++]);
        else
        {
          postfix[j++]=pop();
        }
      }
    }
   while(top!=NULL)
     postfix[j++]=pop();
  postfix[j]='\0';
  return postfix;
}

int main()
{
    Conversion c;
    int n;
    cout<<"Enter length of exp"<<endl;
    cin>>n;
    char *exp;
    exp=new char[n];
    cout<<"Enter expression"<<endl;
    cin>>exp;
    c.Push('#');
    char *e=c.InToPost(exp);
    c.pop();
    printf("%s",e);
    return 0;
}
