//SUBSET SUM PROBLEM

#include<bits/stdc++.h>
using namespace std;

void harsh()
{
    // The value of subset[i][j] will be true if
	// there is a subset of set[0..j-1] with sum
	// equal to i
    int n,sum;
    cin>>n>>sum;
    vector<int> set;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        set.push_back(x);
    }
	bool subset[n + 1][sum + 1];

	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

	 // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	printf("\n");
	}

	//cout<<subset[n][sum];
}


int main()
{
    harsh();
    return 0;
}