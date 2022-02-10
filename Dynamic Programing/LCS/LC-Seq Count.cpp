//LCS

#include<bits/stdc++.h>
using namespace std;

void harsh()
{
     string s1,s2;
	 cin>>s1>>s2;

	 int l1=s1.size();
	 int l2=s2.size();
	 int t[l1+1][l2+1];
	 for(int i=0;i<=l1;i++){
		 t[i][0]=0;
	 }
	 for(int i=1;i<=l2;i++){
		 t[0][i]=0;
	 }
	 for(int i=1;i<=l1;i++){
		 for(int j=1;j<=l2;j++){
			 if (s1[i-1]==s2[j-1]){
				 t[i][j]=1+t[i-1][j-1];
			 }else t[i][j]=max(t[i-1][j],t[i][j-1]);
		 }
	 }
	 cout<<t[l1][l2];
}


int main()
{
    harsh();
    return 0;
}