//COUNT OF SUBSET

#include<bits/stdc++.h>
using namespace std;

void harsh()
{
    int n,sum;
    cin>>n>>sum;
    vector<int> set;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        set.push_back(x);
    }
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
							+ subset[i - 1][j - set[i - 1]];
		}
	}

	cout<<subset[n][sum];
}


int main()
{
    harsh();
    return 0;
}