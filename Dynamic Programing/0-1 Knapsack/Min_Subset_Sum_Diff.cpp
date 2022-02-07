//MINIMUM SUBSET SUM DIFFERENCE

#include<bits/stdc++.h>
using namespace std;

vector<int> harsh(vector<int> set,int n,int sum)
{
	int subset[n + 1][sum + 1];

	for (int i = 0; i <= n; i++)
		subset[i][0] = 1;

	for (int i = 1; i <= sum; i++)
		subset[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

    vector<int> v;
		for (int j = 0; j <= sum; j++) {
        if (subset[n][j])v.push_back(j);
        }
        return v;
}


int findPartiion(vector<int> v, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    
    vector<int> t=harsh(v, n, sum / 2);

    int mn=INT16_MAX;
    for(int i=0;i<t.size();i++){
        mn=min(mn,sum-2*t[i]);
    }
    return mn;
}

int main()
{
    vector<int> v={1,2,7};
    cout<<findPartiion(v,3);
    return 0;
}