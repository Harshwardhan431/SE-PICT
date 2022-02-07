//EQUAL SUM PARTITION

#include<bits/stdc++.h>
using namespace std;

bool harsh(vector<int> set,int n,int sum)
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

	return subset[n][sum];
}


bool findPartiion(vector<int> v, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];

    if (sum % 2 != 0)
        return false;
 
    return harsh(v, n, sum / 2);
}

int main()
{
    vector<int> v={1,5,11,5};
    cout<<findPartiion(v,4);
    return 0;
}