#include<iostream>
using namespace std;

class Node{
    int data;
    bool lbit,rbit;
    Node *left,*right;
public:
    Node(){
        data = 0;
        lbit = rbit = 1;
        left = right = nullptr;
    }
    Node(int x){
        data = x;
        lbit = rbit = 1;
        left = right = nullptr;
    }
    friend class TBT;
};

class TBT{
    Node *head,*root;
public:
    TBT(){
        head = root = nullptr;
    }

    Node* getRoot(){
        return root;
    }

    void insert(int x){
        if(root == nullptr){
            head = new Node(-1);
            root = new Node(x);
            head->lbit = head->rbit = 1;
            root->lbit = root->rbit = 0;
            root->left = root->right = head;
            head->left = root;
            head->right = head;
        }
        else{
            Node *ptr = root;
            Node *temp = new Node(x);
            temp->lbit = temp->rbit = 0;
            while(1){
                if(temp->data < ptr->data){
                    if(ptr->lbit != 0){
                        ptr = ptr->left;
                    }
                    else{
                        ptr->lbit = 1;
                        temp->left = ptr->left;
                        ptr->left = temp;
                        temp->right = ptr;
                        return;
                    }
                }
                else{
                    if(ptr->rbit != 0){
                        ptr = ptr->right;
                    }
                    else{
                        ptr->rbit = 1;
                        temp->right = ptr->right;
                        ptr->right = temp;
                        temp->left = ptr;
                        return;
                    }
                }
            }
        }
    }

    void inorder(Node *t){
        if(root == nullptr){
			
            cout << "Tree is empty" << "\n";
            return;
        }

        while(t->lbit != 0){
            t = t->left;
        }
        while(t != head){
            cout << t->data << " ";
            if(t->rbit != 0){
                t = t->right;
                while(t->lbit != 0){
                    t = t->left;
                }
            }
            else{
                t = t->right;
            }
        }
    }

    void preorder(Node *t){
        if(root == nullptr){
            cout << "Tree is empty" << "\n";
            return;
        }

        while(t != head){
            cout << t->data << " ";
            if(t->lbit == 1){
                t = t->left;
            }
            else{
                if(t->rbit == 1){
                    t = t->right;
                }
                else{
                    while(t->rbit != 1){
                        t = t->right;
                    }
                    t = t->right;
                }
            }
        }
    }

    void search(int x,Node *&loc,Node *&par){
        loc = par = nullptr;
        if(root == nullptr){
            cout << "Tree is empty" << "\n";
            return;
        }

        Node *ptr = root;
        while(ptr != nullptr){
            if(x == ptr->data){
                loc = ptr;
                return;
            }
            else if(x < ptr->data){
                if(ptr->lbit == 1){
                    par = ptr;
                    ptr = ptr->left;
                }
                else ptr = nullptr;
            }
            else{
                if(ptr->rbit == 1){
                    par = ptr;
                    ptr = ptr->right;
                }
                else ptr = nullptr;
            }
        }
    }

    void deleteTBT1(int x,Node *&loc,Node *&par){
        if(par->left == loc){
            par->left = loc->left;
            par->lbit = 0;
        }
        else{
            par->right = loc->right;
            par->rbit = 0;            
        }
        delete loc;
    }

    void deleteTBT2(int x,Node *&loc,Node *&par){
        if(loc->lbit == 0 && loc->rbit == 1){
            Node *temp = loc->right;       
            if(par->right == loc){
                par->right = temp;
            }
            else par->left = temp;
            while(temp->lbit != 0){
                temp = temp->left;
            }
            temp->left = loc->left;
            delete loc;
        }
        else{
            Node *temp = loc->left;
            if(par->left == loc){
                par->left = temp;
            }
            else par->right = temp;
            while(temp->rbit != 0){
                temp = temp->right;
            }
            temp->right = loc->right;
            delete loc;
        }
    }

    void deleteTBT(int x){
        if(root == nullptr){
            cout << "Tree is empty" << "\n";
            return;
        }

        Node *loc,*par;
        search(x,loc,par);
        
        if(loc == nullptr){
            cout << "Node not found" << "\n";
            return;
        }

        if(loc->lbit == 0 && loc->rbit == 0){
            deleteTBT1(x,loc,par);
        }
        else if(loc->lbit != loc->rbit){
            deleteTBT2(x,loc,par);
        }
        else{
            Node* ptr1 = loc;
            Node* ptr2 = loc->right;
            while(ptr2->lbit != 0){
                ptr1 = ptr2;
                ptr2 = ptr2->left; 
            }
            int temp = ptr2->data;
            if(ptr2->lbit == 0 && ptr2->rbit == 0){
                deleteTBT1(ptr2->data,ptr2,ptr1);
            }
            else deleteTBT2(ptr2->data,ptr2,ptr1);
            loc->data = temp;
        }
    }

};

int main(){

    TBT t;
    t.insert(5);
    t.insert(2);
    t.insert(6);
    t.insert(1);
    t.insert(3);
    t.insert(7);
    t.inorder(t.getRoot());
    cout << "\n";
    t.preorder(t.getRoot());
    t.deleteTBT(5);
    cout << "\n";
    t.preorder(t.getRoot());

    return 0;
}