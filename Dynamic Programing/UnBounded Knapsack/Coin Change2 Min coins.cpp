//COIN CHANGE 2 Min number of coins

#include<bits/stdc++.h>
using namespace std;

void harsh()
{
     int n,sum;cin>>n>>sum;
    vector<int> coin;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        coin.push_back(x);
    }

	int t[n + 1][sum+ 1];

	for (int i = 0; i <= n; i++)
		t[i][0] = 0;

	for (int i = 0; i <= sum; i++)
		t[0][i] = INT16_MAX-1;

	for(int j=1;j<=sum;j++){
		if (j%coin[0]==0)t[1][j]=j/coin[0];
		else t[1][j]=INT16_MAX-1;

	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < coin[i - 1])
				t[i][j] = t[i - 1][j];
			if (j >= coin[i - 1])
            t[i][j]=min(t[i][j-coin[i-1]]+1,t[i-1][j]);
		}
	}
    cout<<t[n][sum];
}


int main()
{
    harsh();
    return 0;
}