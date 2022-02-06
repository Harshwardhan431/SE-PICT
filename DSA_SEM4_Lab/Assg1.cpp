/*
Name : Harshwardhan Atkare
Roll No : 21106

Beginning with an empty binary tree, Construct binary tree by inserting the values in the order given.
After constructing a binary tree perform following operations on it-

Perform inorder / preorder and post order traversal
Change a tree so that the roles of the left and right pointers are swapped at every node
Find the height of tree
Copy this tree to another [operator=]
Count number of leaves, number of internal nodes.
Erase all nodes in a binary tree.
(implement both recursive and non-recursive methods)
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *lchild=nullptr;
    Node *rchild=nullptr;
    explicit Node(int d)
    {
        data=d;
    }
    friend class Tree;
    friend class Node_Stack;
    friend class Stack;
};

class Node_Stack
{
    Node *address=nullptr;
    Node_Stack *next;
    public:
    Node_Stack()
    {
        next=NULL;
    }
    friend class Stack;
};

class Stack
{
    Node_Stack *top;
    public:
    Stack(){
        top=NULL;
    }
    void Push(Node *t);
    Node* Pop();
    bool isEmpty();
};

bool Stack::isEmpty()
{
    if (top==nullptr){
        return true;
    }else {
        return false;
    }
    cout<<"end"<<endl;
}

Node* Stack::Pop()
{
    Node_Stack *p;
    Node *x=nullptr;
    if (top==NULL)
    {
        cout<<"UnderFlow"<<endl;
    }else{
        p=top;
        top=top->next;
        x=p->address;
        delete p;
    }
    return x;
}

void Stack::Push(Node *p)
{
    Node_Stack *t=new Node_Stack;
    if (t==NULL)
    {
        cout<<"Stack OverFlow"<<endl;
    }else{
        t->address=p;
        t->next=top;
        top=t;
    }
}

class Tree
{
    Node *root;
    public:
    Tree()
    {
        root=NULL;
    }
    void create(int x);
    Node *Insert(Node *t,int x);
    void PreOrder_Rec(Node *t);
    void InOrder_Rec(Node *t);
    void PostOrder_Rec(Node *t);
    void PreOrder_Iter(Node *t);
    void InOrder_Iter(Node *t);
    void PostOrder_Iter(Node *t);
    int Height(Node *t);
    Node* AccessRootNode();
    int LeafNode(Node *t);
    int TotalNode(Node *t);
    void EraseAllNode(Node *t);
    Node* deleteLeaves(Node *t,int x);
    Node* Mirror(Node *t);
    Node* Copy(Node *t);
};

Node* Tree::Copy(Node *t)
{
    if (t==NULL)return t;

        Node *temp=new Node(t->data);
        temp->lchild=Copy(t->lchild);
        temp->rchild=Copy(t->rchild);
        return temp;
}

Node* Tree::Mirror(Node *t)
{
    if (t==NULL)return NULL;
    
    Node* left;
    Node* right;

    if (t){
        left=Mirror(t->lchild);
        right=Mirror(t->rchild);
        
        Node* temp=t->lchild;
        t->lchild=t->rchild;
        t->rchild=temp;
    }
    return t;
}

void Tree::PreOrder_Iter(Node *t)
{
    Stack st;
    while (t!=NULL || st.isEmpty()==false)
    {
        if (t!=NULL)
        {
            cout<<t->data<<" ";
            st.Push(t);
            t=t->lchild;
        }else{
            t=st.Pop();
            t=t->rchild;
        }
    }
}

Node* Tree::deleteLeaves(Node *t,int x)
{
    if (t==NULL)return NULL;
    root->lchild=deleteLeaves(t->lchild,x);
    root->rchild=deleteLeaves(t->rchild,x);

    if (t->data==x && t->lchild==NULL && t->rchild==NULL){
        cout<<t->data<<" deleted successfully "<<endl;
        delete (t);
        return NULL;
    }
    return t;
}

void Tree::EraseAllNode(Node *t)
{
    if (t==NULL)return;
    EraseAllNode(t->lchild);
    EraseAllNode(t->rchild);

    cout<<"Deleting "<<t->data<<endl;
    delete t;
}

int Tree::TotalNode(Node *t)
{
    int count=0;
    Stack st;
    while (t!=NULL || st.isEmpty()==false)
    {
        count++;
        if (t!=NULL)
        {
            st.Push(t);
            t=t->lchild;
        }else{
            t=st.Pop();
            t=t->rchild;
        }

    }
    return count;
}

int Tree::LeafNode(Node *t)
{
    int count=0;
    Stack st;
    while (t!=NULL || st.isEmpty()==false)
    {
       if (t!=NULL)
       {
            if (t->lchild==NULL && t->rchild==NULL){
            count++;
        }
       }
        if (t!=NULL)
        {
            st.Push(t);
            t=t->lchild;
        }else{
            t=st.Pop();
            t=t->rchild;
        }

    }
    return count;
}

int Tree::Height(Node *t)
{
    int l=0,r=0;
    if (t==nullptr){
        return 0;
    }
    l=Height(t->lchild);
    r=Height(t->rchild);

    if (l>r)return (l+1);
    else return (r+1);
}

void Tree::PostOrder_Iter(Node *t)
{
    Stack st;
    Node* temp;
    while (t!=NULL || st.isEmpty()==false)
    {
        if (t!=NULL){
            st.Push(t);
            t=t->lchild;
        }else{
            temp=st.Pop();
            if (temp->data>0){
                temp->data=-temp->data;
                st.Push(temp);
                t=temp->rchild;
            }else{
                temp->data=-temp->data;
                cout<<(temp->data)<<" ";
                t=NULL;
            }
        }
    }
}

void Tree::InOrder_Iter(Node *t)
{
    Stack st;
    while (t!=NULL || st.isEmpty()==false)
    {
        if (t!=NULL)
        {
            st.Push(t);
            t=t->lchild;
        }else{
            t=st.Pop();
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
    
}

void Tree::PostOrder_Rec(Node *t)
{
    if (t!=NULL)
    {
        PostOrder_Rec(t->lchild);
        PostOrder_Rec(t->rchild);
        cout<<t->data<<" ";
    }
}

void Tree::InOrder_Rec(Node *t)
{
    if (t!=NULL)
    {
        InOrder_Rec(t->lchild);
        cout<<t->data<<" ";
        InOrder_Rec(t->rchild);
    }
}

Node* Tree::AccessRootNode()
{
    return root;
}


void Tree::PreOrder_Rec(Node *t)
{
    if (t!=NULL)
    {
        cout<<t->data<<" ";
        PreOrder_Rec(t->lchild);
        PreOrder_Rec(t->rchild);
    }
}

void Tree::create(int x)
{
    if (root==NULL){
        root=new Node(x);
    }else{
        Insert(root,x);
    }
}

Node* Tree::Insert(Node *t,int x)
{
    Node *p;
    if (t==nullptr)
    {
        p=new Node(x);
        return p;
    }else{
        char choice;

        cout<<"Enter L to enter Node at left child at "<<t->data<<endl;
        cout<<"Enter R to enter Node at right child at "<<t->data<<endl;
        cin>>choice;
        if (choice=='L')
        {
            
            t->lchild=Insert(t->lchild,x);
        }else if (choice=='R')
        {
            t->rchild=Insert(t->rchild,x);
        }
    }
    return t;
}

int main()
{
    Tree t;
    int choice=0;
    while (choice!=-1)
    {
        cout<<"Enter 1 to create the Tree"<<endl;
        cout<<"Enter 2 to insert element in Tree"<<endl;
        cout<<"Enter 3 for PreOrder Recursive Travsel"<<endl;
        cout<<"Enter 4 for InOrder Recursive Travsel"<<endl;
        cout<<"Enter 5 for PostOrder Recursive Travsel"<<endl;
        cout<<"Enter 6 for PreOrder Iterative Travsel"<<endl;
        cout<<"Enter 7 for InOrder Iterative Travsel"<<endl;
        cout<<"Enter 8 to get Height of Tree"<<endl;
        cout<<"Enter 9 to get Number of leaf Nodes"<<endl;
        cout<<"Enter 10 to get Number of internal Nodes"<<endl;
        cout<<"Enter 11 to get PostOrder Iterative Travsel"<<endl;
        cout<<"Enter 12 to get mirror image of the Tree"<<endl;
        cout<<"Enter 13 to copy the tree into another tree"<<endl;
        cout<<"Enter 14 to erase of Nodes "<<endl;
        cout<<"Enter -1 to exit"<<endl;
        cout<<"Enter choice"<<endl;
        cin>>choice;
        if (choice==1)
        {
            cout<<"Enter the root value"<<endl;
            int x;cin>>x;
            t.create(x);
        }else if (choice==2)
        {
            cout<<"Enter the value to be inserted"<<endl;
            int x;cin>>x;
            t.create(x);
        }else if (choice==3)
        {
            Node *i=t.AccessRootNode();
            t.PreOrder_Rec(i);
            cout<<endl;
        }
        else if (choice==4)
        {
            Node *i=t.AccessRootNode();
            t.InOrder_Rec(i);
            cout<<endl;
        }
        else if (choice==5)
        {
            Node *i=t.AccessRootNode();
            t.PostOrder_Rec(i);
            cout<<endl;
        }
        else if (choice==6)
        {
            Node *i=t.AccessRootNode();
            t.PreOrder_Iter(i);
            cout<<endl;
        }
        else if (choice==7)
        {
            Node *i=t.AccessRootNode();
            t.InOrder_Iter(i);
            cout<<endl;
        }
        else if (choice==8)
        {
            Node *i=t.AccessRootNode();
            cout<<"Height of the Tree is :- ";
            cout<<t.Height(i)<<endl;
        }
        else if (choice==9)
        {
            Node *i=t.AccessRootNode();
            cout<<"No of Leaf Nodes are :- "<<t.LeafNode(i)<<endl;
        }
        else if (choice==10)
        {
            Node *i=t.AccessRootNode();
            cout<<"No of Internal Nodes are :- "<<((t.TotalNode(i)/2)-t.LeafNode(i))<<endl;
        }
        else if (choice==11)
        {
            Node *i=t.AccessRootNode();
            t.PostOrder_Iter(i);
            cout<<endl;
        }
        else if (choice==12)
        {
            Node *i=t.AccessRootNode();
            t.Mirror(i);
            cout<<"The PreOrder Travsel of the mirror image is :-"<<endl;
            t.PreOrder_Rec(i);
            cout<<endl;
        }
        else if (choice==13)
        {
           Node *i=t.AccessRootNode();
           Tree t1;
           Node *root1=t1.Copy(i);
           cout<<"PreOrder travsel of the Copied tree is :- "<<endl;
           t1.PreOrder_Rec(root1);
           cout<<endl;
        }
        else if (choice==14)
        {
            Node *i=t.AccessRootNode();
            t.EraseAllNode(i);
        }
        else if (choice==-1)
        {
            break;
        }
    }

    return 0;
}