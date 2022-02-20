#include <iostream>
using namespace std;

class Node
{
	Node *lchild;
	Node *rchild;
	int data;
	string s;

public:
	Node(int x, string str)
	{
		data = x;
		s = str;
	}
	friend class BST;
};

class BST
{
	Node *root;

public:
	BST()
	{
		root = NULL;
	}
	void create(int x, string s);
	void Preorder(Node *t);
	void Inorder(Node *t);
	void Descending(Node *t);
	Node *getRoot();
	Node *RSearch(Node *t, int key);
	void Delete(Node *t, int x);
};

void BST::Descending(Node *t)
{
	if (t != NULL)
	{
		Inorder(t->rchild);
		cout << "{" << t->data << " -  " << t->s << "}" << endl;
		Inorder(t->lchild);
	}
}

void BST::Delete(Node *t, int x)
{
	Node *curr = t;
	Node *par = NULL;

	while (curr->data != x && curr != NULL)
	{
		if (curr->data > x)
		{
			par = curr;
			curr = curr->lchild;
		}
		else
		{
			par = curr;
			curr = curr->rchild;
		}
	}

	if (curr->data == t->data)
	{
		if (curr->lchild == NULL && curr->rchild == NULL)
		{
			root = NULL;
			free(curr);
		}
		else if (curr->lchild == NULL && curr->rchild != NULL)
		{
			root = curr->rchild;
			free(curr);
		}
		else if (curr->lchild != NULL && curr->rchild == NULL)
		{
			root = curr->lchild;
			free(curr);
		}
		else
		{
			Node *temp = curr->lchild;
			Node *b = NULL;
			while (temp->rchild)
			{
				b = temp;
				temp = temp->rchild;
			}
			curr->data = temp->data;
			if (temp->lchild != NULL)
			{

				b->rchild = temp->rchild;
				free(temp);
			}
			else
			{
				free(temp);
			}
		}
	}
	else
	{
		if (curr->lchild == NULL && curr->rchild == NULL)
		{

			if (par->lchild == curr)
			{
				par->lchild = NULL;
			}
			else
			{
				par->rchild = NULL;
			}
			free(curr);
		}
		else if (curr->lchild != NULL && curr->rchild == NULL)
		{
			if (par->lchild == curr)
			{
				par->lchild = curr->lchild;
			}
			else
			{
				par->rchild = curr->lchild;
			}
			free(curr);
		}
		else if (curr->rchild != NULL && curr->lchild == NULL)
		{
			if (par->lchild == curr)
			{
				par->lchild = curr->rchild;
			}
			else
			{
				par->rchild = curr->rchild;
			}
			free(curr);
		}
		else if (curr->lchild != NULL && curr->rchild != NULL)
		{
			Node *temp = curr->lchild;
			Node *b = NULL;
			while (temp->rchild)
			{
				b = temp;
				temp = temp->rchild;
			}
			curr->data = temp->data;
			if (temp->lchild != NULL)
			{

				b->rchild = temp->rchild;
				free(temp);
			}
			else
			{
				free(temp);
			}
		}
	}
}

Node *BST::RSearch(Node *t, int key)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (key == t->data)
	{
		cout << "Key " << t->data << " as value " << t->s << endl;
		return t;
	}
	else if (key < t->data)
	{
		return RSearch(t->lchild, key);
	}
	else
	{
		return RSearch(t->rchild, key);
	}
}

void BST::Inorder(Node *t)
{
	if (t != NULL)
	{
		Inorder(t->lchild);
		cout << "{" << t->data << " -  " << t->s << "}" << endl;
		Inorder(t->rchild);
	}
}

Node *BST::getRoot()
{
	return root;
}

void BST::create(int x, string s)
{
	Node *n = new Node(x, s);
	Node *p;
	if (root == NULL)
	{
		n->lchild = NULL;
		n->rchild = NULL;
		root = n;
		cout << "Root node successfully created" << endl;
	}
	else
	{
		p = root;
		while (1)
		{
			if (x < p->data)
			{
				if (p->lchild != NULL)
				{
					p = p->lchild;
				}
				else
				{
					n->lchild = n->rchild = NULL;
					p->lchild = n;
					return;
				}
			}
			else
			{
				if (p->rchild != NULL)
				{
					p = p->rchild;
				}
				else
				{
					n->lchild = n->rchild = NULL;
					p->rchild = n;
					return;
				}
			}
		}
	}
}

int main()
{
	int choice;
	BST t;
	while (1)
	{
		cout << "Enter 1 to insert node " << endl;
		cout << "Enter 2 to get ascending order values" << endl;
		cout << "Enter 3 to search for a key" << endl;
		cout << "Enter 4 to delete node" << endl;
		cout<<"Enter 5 to desending data"<<endl;
		cout << "Enter -1 to exit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			Node *i = t.getRoot();
			int x;
			cout << "Enter the key" << endl;
			cin >> x;
			string s;
			cout << "Enter the value at key " << x << endl;
			cin >> s;
			if (t.RSearch(i, x) == NULL)
			{
				t.create(x, s);
			}
			else
			{
				cout << "Key already exist" << endl;
				cout << "Want to update key " << x << " with " << s << " ?" << endl;
				char f;
				cout << "Y/N" << endl;
				cin >> f;
				if (f == 'Y')
				{
					// t.Update(i,x,s);
				}
				else
				{
					cout << "Key not updated" << endl;
				}
			}
		}
		else if (choice == 2)
		{
			Node *i = t.getRoot();
			t.Inorder(i);
			cout << endl;
		}
		else if (choice == 3)
		{
			Node *i = t.getRoot();
			int x;
			cout << "Enter data you want to search" << endl;
			cin >> x;

			if (t.RSearch(i, x) == NULL)
			{

				cout << "Nodes not found" << endl;
			}
		}
		else if (choice == 4)
		{
			Node *i = t.getRoot();
			int x;
			cout << "Enter the data you want to delete" << endl;
			cin >> x;
			if (t.RSearch(i, x) == NULL)
			{
				cout << "Key dosenot exist" << endl;
			}
			else
				t.Delete(i, x);
		}else if (choice==5){
			Node *i = t.getRoot();
			t.Descending(i);
		}
		else if (choice == -1)
		{
			break;
		}
	}
	return 0;
}
