/*
Second year Computer Engineering class, set A of students like Vanilla
 Ice-cream and set B of students like butterscotch ice-cream. 
 Write C++ program to store two sets using linked list. compute and display- 
	a) Set of students who like both vanilla and butterscotch 
	b) Set of students who like either vanilla or butterscotch or not both 
	c) Number of students who like neither vanilla nor butterscotch 
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
 public:
    int data;
    Node *next;
};
class LinkedList
{
 private:
    Node *first,*second;
 public:
    LinkedList(){first=NULL;second=NULL;}
    ~LinkedList();

    void Display();
    void Insert(int index,int x);
    int Delete(int index);
    int Length();
    void Intersection(Node *a,Node *b);
};
void LinkedList::Intersection(Node *a,Node *b){

}

LinkedList::~LinkedList()
{
    Node *p=first;
 while(first)
 {
   first=first->next;
   delete p;
   p=first;
 }
}
void LinkedList::Display()
{
    Node *p=first;

 while(p)
 {
 cout<<p->data<<" ";
 p=p->next;
 }
 cout<<endl;
}
int LinkedList::Length()
{
    Node *p=first;
 int len=0;

 while(p)
 {
 len++;
 p=p->next;
 }
 return len;
}
void LinkedList::Insert(int index,int x)
{
    Node *t,*p=first;

   if(index <0 || index > Length())
     return;
   t=new Node;
   t->data=x;
   t->next=NULL;

   if(index==0)
   {
     t->next=first;
     first=t;
   }
   else
   {
     for(int i=0;i<index-1;i++)
         p=p->next;
     t->next=p->next;
     p->next=t;
   }
}
int LinkedList::Delete(int index)
{
    Node *p,*q=NULL;
    int x=-1;

    if(index < 1 || index > Length())
        return -1;
    if(index==1)
    {
      p=first;
      first=first->next;
      x=p->data;
      delete p;
    }
    else
    {
       p=first;
       for(int i=0;i<index-1;i++)
       {
          q=p;
          p=p->next;
       }
     q->next=p->next;
     x=p->data;
     delete p;
    }
 return x;
}
int main()
{
    LinkedList vanilla;
	cout<<"Enter number of students who like vanilla"<<endl;
	int v;cin>>v;
    cout<<"Enter the roll no of students who like vanilla"<<endl;
	for(int i=0;i<v;i++){
		int x;cin>>x;
        vanilla.Insert(i,x);
	}
    LinkedList butterstoch;
    cout<<"Enter number of studentswho like butterscotch"<<endl;
	int b;cin>>b;
    cout<<"Enter the roll no of students who like butterscotch"<<endl;
	for(int i=0;i<b;i++){
		int x;cin>>x;
		butterstoch.Insert(i,x);
	}
    LinkedList intersection;
    
    
    return 0;
}