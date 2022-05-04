#include <iostream>
using namespace std;
#define I 32167

class Graph
{
	int vertices, edges;
	int **adj;

public:
	Graph(int v, int e)
	{
		vertices = v;
		edges = e;
		adj = new int *[v];
		for (int i = 0; i < v; i++)
		{
			adj[i] = new int[vertices];
		}
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				adj[i][j] = I;
			}
		}
	}

	void Insert()
	{
		for (int i = 0; i <= edges; i++)
		{
			cout << "Enter source" << endl;
			int s;
			cin >> s;
			cout << "Enter destination" << endl;
			int d;
			cin >> d;
			cout << "Enter weight" << endl;
			int w;
			cin >> w;
			adj[s][d] = w;
			adj[d][s] = w;
		}
	}

	void DisplayMatrix()
	{
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 1; j < edges; j++)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Prim()
	{
		int near[8];
		int t[2][6];
		//Initizing near array with infinity
		for (int i = 0; i < 8; i++)
		{
			near[i] = I;
		}

		int k, u, v, n = 7, min = I;
        
		//finding min element in the matrix
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (adj[i][j] < min)
				{
					min = adj[i][j];
					u = i;
					v = j;
				}
			}
		}

		t[0][0] = u;
		t[1][0] = v;
		near[u] = near[v] = 0;

        //Initizing near array with the min element 
		for (int i = 1; i <= n; i++)
		{
			if (adj[i][u] < adj[i][v] && near[i] != 0)
			{
				near[i] = u;
			}
			else if (adj[i][u]>=adj[i][v] && near[i]!=0)
			{
				near[i] = v;
			}
		}
		
		//repeat
		for (int i = 1; i < n - 1; i++)
		{
			min = I;
			for (int j = 1; j <= n; j++)
			{
				if (near[j] != 0 && adj[j][near[j]] < min)
				{
					min = adj[j][near[j]];
					k = j;
				}
			}
			t[0][i] = k;
			t[1][i] = near[k];
			near[k] = 0;

			for (int j = 1; j <= n; j++)
			{
				if (near[j] != 0 && adj[j][k] < adj[j][near[j]])
				{
					near[j] = k;
				}
			}
		}
		cout<<"Minimun spaming tree edges :-"<<endl;
		int sum=0;

		for(int i=0;i<6;i++){
			sum+=adj[t[0][i]][t[1][i]];
			cout<<"["<<t[0][i]<<"]---["<<t[1][i]<<"] -> "<<adj[t[0][i]][t[1][i]]<<endl;
		}
		cout<<"Min path length is ->"<<sum<<endl;
	}

};

int main()
{
	Graph g(8, 8);
	g.Insert();
	g.DisplayMatrix();
	cout<<endl;
	g.Prim();
}