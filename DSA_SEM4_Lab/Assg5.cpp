#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
public:
	friend class LinkedList;
};

class LinkedList{
private:
    Node *first;
 public:
    friend class ChainHash;
    LinkedList(){first=nullptr;}
    ~LinkedList();

    void Display();
    void Insert(int index,int x);
    int Delete(int index);
    int Length();
};

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
	   t->next=nullptr;

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

class ChainHash{
private:
	int bucket;
	LinkedList *l;
public:
	ChainHash(int b){
		bucket=b;

	}

	int hashFunction(int x) {
        return (x % bucket);
    }

	void insertItem(int key)
	{
		cout<<"euu"<<endl;
		int index = hashFunction(key);
		int length=l->Length();
		cout<<index<<" "<<length;
		l[index].Insert((length-1), key);
	}

	void printHash(){
		for (int i = 0; i < bucket; i++) {
		    cout << i;
		    l[i].Display();
		    cout<<endl;
	}
	}
};

int main(){
	ChainHash c(10);
	cout<<"Enter 1 to insert value"<<endl;
	cout<<"Enter 2 to print linkedlist"<<endl;
	cout<<"Enter -1 to exit"<<endl;
	int choice;
	cin>>choice;
	while(1){
		if (choice==1){
			int x;
			cout<<"Enter value to be inserted"<<endl;
			cin>>x;
			c.insertItem(x);
		}else if (choice==2){
			c.printHash();
		}else if (choice==-1){
			break;
		}
		}
	return 0;
	}
