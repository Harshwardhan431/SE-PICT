#include<iostream>
#include<queue>
using namespace std;

class Node{
    int data;
    Node* link;
    public:
    Node()
    {
        data=0;
        link=nullptr;
    }
    Node(int x){
        data=x;
        link=nullptr;
    }
    friend class Graph;
};

class Graph{
    int vertices,edges;
    Node** head;
    int *indegree;
    public:
    Graph()
    {
        vertices=0;
        edges=0;
        head=new Node*[vertices];
        indegree=new int[vertices];
        for(int i=0;i<vertices;i++){
            head[i]->data=0;
            head[i]->link=nullptr;
        }
        for(int i=0;i<vertices;i++){
            indegree[i]=0;
        }
    }
    Graph(int verti,int edg){
        //cout<<"Constructor creation started"<<endl;
        vertices=verti;
        edges=edg;
        head=new Node*[vertices];
        indegree=new int[vertices];
        for(int i=0;i<vertices;i++){
            head[i]=nullptr;
        }
        for(int i=0;i<vertices;i++){
            indegree[i]=0;
        }
        //cout<<"Constructor created successfully"<<endl;
    }
    void createGraph();
    void displayAdjancy();
    void displayIndegree();
    void topologySort();
};

void Graph::topologySort()
{
    queue<int> q;
    int pos;
    for(int i=0;i<vertices;i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int poped=q.front();
        cout<<poped<<" ";
        q.pop();
        Node* temp=head[poped];
        
        while (temp!=nullptr)
        {
            indegree[temp->data]--;
            if (indegree[temp->data]==0){
                q.push(temp->data);
            }
            temp=temp->link;
           // displayIndegree();
        }
        cout<<"";
    }cout<<endl;
    
}

void Graph::displayAdjancy()
{
    for(int i=0;i<vertices;i++){
        Node* p=head[i];
        cout<<i<<" : ";
        while (p!=nullptr)
        {
            cout<<p->data<<" ";
            p=p->link;
        }
        cout<<endl;
    }
}

void Graph::displayIndegree()
{
    cout<<"Indgree:- ";
    for(int i=0;i<vertices;i++){
        cout<<indegree[i]<<" ";
    }cout<<endl;
}

void Graph::createGraph()
{
   // cout<<"Creation started"<<endl;
    for(int i=0;i<edges;i++){
        int source;
    cout<<"Enter the source"<<endl;
    cin>>source;
    int destination;
    cout<<"Enter the destination"<<endl;
    cin>>destination;
    Node* tempsource=new Node(destination);

    if (head[source]==nullptr){
        head[source]=tempsource;
    }
    else{
        Node* p=head[source];
    while (p->link!=nullptr)
    {
        p=p->link;
    }
    p->link=tempsource;
   // cout<<tempsource->data<<" kdkd"<<endl;
    
    }
    indegree[tempsource->data]++;
    }
}

int main()
{
    int v;
    cout<<"Enter number of vertices"<<endl;
    cin>>v;
    int e;
    cout<<"Enter number of edges"<<endl;
    cin>>e;
    Graph g(v,e);
    g.createGraph();
    g.displayIndegree();
    g.displayAdjancy();
    g.topologySort();
        return 0;
}