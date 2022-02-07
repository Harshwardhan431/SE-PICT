//ROD CUTTING PROBLEM

#include<bits/stdc++.h>
using namespace std;

void harsh(vector<int> price,int n)
{
    vector<int> length;
    for(int i=0;i<n;i++){
        length.push_back(i+1);
    }
	int t[n + 1][n+ 1];

	for (int i = 0; i <= n; i++)
		t[i][0] = 0;

	for (int i = 1; i <= n; i++)
		t[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < length[i - 1])
				t[i][j] = t[i - 1][j];
			if (j >= length[i - 1])
            t[i][j]=max(price[i-1]+t[i][j-length[i-1]],
            t[i-1][j]);
		}
	}
    cout<<t[n][n];
}

void yash()
{
    int n;cin>>n;
    vector<int> price;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        price.push_back(x);
    }
    harsh(price,n);
}

int main()
{
    yash();
    return 0;
}