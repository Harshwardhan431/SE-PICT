//Longest common substring 
//I/P : abcabcbb
//O/P : 3

#include<bits/stdc++.h>
using namespace std;

 int lengthOfLongestSubstring(string s) {
     vector<int> v(256,-1);
     for(int i=0;i<v.size();i++){
         cout<<v[i]<<" ";
     }
     if (s.size()==0)return 0;
     int start=-1;
     int length=0;
     for(int i=0;i<s.size();i++)
     {
         if (v[s[i]]>start){
             start=v[s[i]];
             v[s[i]]=i;
             length=max(length,i-start);
         }else{
             v[s[i]]=i;
             length=max(length,i-start);
         }
     }
     return length;
 }

 int main()
 {
     cout<<lengthOfLongestSubstring("abcabcb");
     return 0;
 }