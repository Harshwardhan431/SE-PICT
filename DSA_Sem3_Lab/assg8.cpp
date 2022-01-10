/*
Harshwardhan Atkare
21106

Second year Computer Engineering class, set A of students like Vanilla
 Ice-cream and set B of students like butterscotch ice-cream. 
 Write C++ program to store two sets using linked list. compute and display- 
	a) Set of students who like both vanilla and butterscotch 
	b) Set of students who like either vanilla or butterscotch or not both 
	c) Number of students who like neither vanilla nor butterscotch
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
}*first=NULL,*second=NULL,*intersection=NULL,*union1=NULL,*all=NULL,*non=NULL,*tmp=NULL;

class Set{
    public:
    void addLast(Node **head,int val);
    int count(Node *p);
    void display(Node *p);
    void Intersection(Node *a,Node *b);
    void Uni(Node *a,Node *b);
    void NeitherNor(Node *a,Node *b,Node *c);
};

void Set::addLast(Node **head,int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL)
         *head = newNode;

    else
    {
        Node *lastNode = *head;
    
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}



int Set::count(Node *p)
{
    int l=0;
     while(p)
     {
         l++;
         p=p->next;
     }
     return l;
}

void Set::display(Node *p)
{
    while (p!=NULL)
	{
		
		cout<<p->data<<" ";
		p=p->next;
	}
}

void Set::Intersection(Node *a,Node *b)
{
    int t=0;
    if (count(a)>count(b)){t=1;}
   if (t==0){
       while (a!=NULL)
       {
          while (b!=NULL)
           {
               if (a->data==b->data){
                  addLast(&intersection,a->data);
               }
               b=b->next;
           }
           b=second;
           a=a->next; 
       }
   }else{
       while (b!=NULL)
       {
          while (a!=NULL)
           {
               if (a->data==b->data){
                 addLast(&intersection,a->data);
               }
               a=a->next;
           }
           a=first;
           b=b->next; 
       }
   }  
}

void Set::Uni(Node *a,Node *b)
{
    while (a!=NULL && b!=NULL)
    {
        if (a->data<b->data){
        addLast(&union1,a->data);
        a=a->next;
        }else if (a->data>b->data){
        addLast(&union1,b->data);
        b=b->next;
        }else{
            addLast(&union1,a->data);
            a=a->next;
            b=b->next;
        }
    }
    while (a!=NULL)
    {
            addLast(&union1,a->data);
            a=a->next;
    }
    while (b!=NULL)
    {
         addLast(&union1,b->data);
            b=b->next;
    }
}

void Set::NeitherNor(Node *a,Node *b,Node *c)
{
    while (a!=NULL && b!=NULL)
    {
        if (a->data<b->data){
        addLast(&tmp,a->data);
        a=a->next;
        }else if (a->data>b->data){
        addLast(&tmp,b->data);
        b=b->next;
        }else{
            addLast(&tmp,a->data);
            a=a->next;
            b=b->next;
        }
    }
    while (a!=NULL)
    {
            addLast(&tmp,a->data);
            a=a->next;
    }
    while (b!=NULL)
    {
         addLast(&tmp,b->data);
            b=b->next;
    }
   
   Node *t=tmp;
   bool f=false;
    while (all!=NULL)
    {
        while (tmp!=NULL)
        {
            if (all->data==tmp->data){
                f=true;
                break;
            }
            tmp=tmp->next;
        }
        if (f==false){
            addLast(&non,all->data);
        }
        f=false;
        tmp=t;
        all=all->next;
    }
}

int main()
{
    Set s;
    cout<<"Enter total number of students"<<endl;
    int n;cin>>n;
    cout<<"Enter roll no of all students"<<endl;
    for(int i=0;i<n;i++){
		int x;cin>>x;
        s.addLast(&all,x);
	}
	
	cout<<"Enter number of students who like vanilla"<<endl;
	int v;cin>>v;
    cout<<"Enter the roll no of students who like vanilla"<<endl;
	for(int i=0;i<v;i++){
		int x;cin>>x;
        s.addLast(&first,x);
	}
	cout<<"Enter number of studentswho like butterscotch"<<endl;
	int b;cin>>b;
    cout<<"Enter the roll no of students who like butterscotch"<<endl;
	for(int i=0;i<b;i++){
		int x;cin>>x;
        s.addLast(&second,x);
	}
    int choice;
    cout<<"Enter 1-> For Intersection"<<endl;
    cout<<"Enter 2-> For Union"<<endl;
    cout<<"Enter 3-> For Neither Nor"<<endl;
    cout<<"Enter 4-> For exit"<<endl;
    cin>>choice;
    int cont;
    while (1)
    {
        if (choice==1){
        s.Intersection(first,second);
    cout<<"Set of students who like both"<<endl;
    s.display(intersection);
    cout<<endl;
    }else if (choice==2){
        s.Uni(first,second);
    cout<<" Set of students who like either vanilla or butterscotch or not both"<<endl;
    s.display(union1);
    cout<<endl;
    }else if (choice==3){
        s.NeitherNor(first,second,all);
    cout<<"Number of students who like neither vanilla nor butterscotch"<<endl;
    s.display(non);
    cout<<endl;
    }
    cout<<"Enter 1 if want to continue or enter 0"<<endl;
    cin>>cont;
    if (cont==0){
        break;
    }else if (cont==1){
          cout<<"Enter 1-> For Intersection"<<endl;
    cout<<"Enter 2-> For Union"<<endl;
    cout<<"Enter 3-> For Neither Nor"<<endl;
    cout<<"Enter 4-> For exit"<<endl;
        
        cin>>choice;
    }else{
      cout<<"Enter bettween 0 and 1"<<endl;
        cin>>cont;
    }
    }
    return 0;
}
