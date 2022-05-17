/*
Represent a given using adjancency list to perform DFS and BFS. 
Use the map of the area around the college as the graph.
Identify the prominent landmarks as nodes and perform DFS and BFS on that
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node* link;
    public:
    Node()
    {
        data=0;
        link=nullptr;
    }
    Node(int x)
    {
        data=x;
        link=nullptr;
    }
    friend class Graph;
};

class Graph{
    int vertices,edges;
    Node** head;
    public:
    Graph(){
        vertices=edges=0;
        head=new Node*[vertices];
        for(int i=0;i<vertices;i++){
            head[i]=nullptr;
        }
    }

    Graph(int v,int e)
    {
        vertices=v;
        edges=e;
        head=new Node*[vertices];
        for(int i=0;i<vertices;i++)
        {
            head[i]=nullptr;
        }
    }

    void Create()
    {
        for(int i=0;i<edges;i++)
        {
            int source,destination;
            cout<<"Enter the source"<<endl;
            cin>>source;
            cout<<"Enter the destination"<<endl;
            cin>>destination;
            
            Node* temp=head[source];
            Node* n=new Node(destination);

            if (temp==nullptr)
            {
                head[source]=n;
            }
            else{
                while (temp->link!=nullptr)
                {
                    temp=temp->link;
                }
                temp->link=n;
            }
            
        }
    }

    void Display()
    {
        for(int i=0;i<vertices;i++)
        {
            Node* t=head[i];
            cout<<i<<" ";
            while (t!=nullptr)
            {
                cout<<t->data<<" -> ";
                t=t->link;
            }
            cout<<endl;
        }
    }

    void BFS()
    {
        bool isvisited[vertices];
        for(int i=0;i<vertices;i++){
            isvisited[i]=false;
        }

        queue<int> q;
        int starting=0;
        q.push(starting);
        while (!q.empty())
        {
            int popped=q.front();
            q.pop();
            if (isvisited[popped]!=true){
                Node* temp=head[popped];
                isvisited[popped]=true;
                cout<<popped<<" ";
                while (temp!=nullptr)
                {
                    if (isvisited[temp->data]!=true){
                        q.push(temp->data);
                    }
                }
                
            }
            
        }
        
    }

    void DFS()
    {
        stack<int> s;
        bool visited[vertices];
        for(int i=0;i<vertices;i++){
            visited[i]=false;
        }
        int starting=0;
        s.push(starting);
        while (!s.empty())
        {
            int popped=s.top();
            s.pop();
            if (visited[popped]!=true){
                Node* temp=head[popped];
                visited[popped]=true;
                cout<<popped<<" ";
            while (temp!=nullptr)
            {
                if (visited[temp->data]!=true){
                    s.push(temp->data);
                }
                temp=temp->link;
            }
            }  
        }
        cout<<endl;
    }
};

int main()
{
    int choice;

    int vertex,edge;
    cout<<"Enter the number of the vertices of the graph"<<endl;
    cin>>vertex;
    cout<<"Enter the number of the edges of the graph"<<endl;
    cin>>edge;

    Graph g(vertex,edge);
    while (1)
    {
        cout<<"Enter 1 to create graph"<<endl;
        cout<<"Enter 2 to Display graph"<<endl;
        cout<<"Enter 3 to get BFS pf the graph"<<endl;
        cout<<"Enter 4 to get DFS of the graph"<<endl;
        cout<<"Enter -1 to exit"<<endl;
        cin>>choice;
        if (choice==1){
            g.Create();
        }else if (choice==2){
            g.Display();
        }else if (choice==3){
            g.BFS();
        }else if (choice==4){
            g.DFS();
        }
        else if (choice==-1){
            break;
        }
    }
    
}
