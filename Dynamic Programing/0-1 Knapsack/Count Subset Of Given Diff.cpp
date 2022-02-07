//COUNT OF NUMBER OF SUBSET OF GIVEN DIFF..

#include<bits/stdc++.h>
using namespace std;

void harsh(vector<int> set,int n,int sum)
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
							+ subset[i - 1][j - set[i - 1]];
		}
	}

	cout<<subset[n][sum];
}

void yash()
{
    vector<int> v;
    int n,diff;
    cin>>n>>diff;
    int sumArr=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        sumArr+=x;
        v.push_back(x);
    }
    int sum=(diff+sumArr)/2;
    harsh(v,n,4);
}


int main()
{
    yash();   
    return 0;
}