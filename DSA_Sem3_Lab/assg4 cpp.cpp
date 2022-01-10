/*
Searching:-----
1.Binary Search
2.Fibbonacci Search
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> v,int x){
  cout<<"Starts-------------"<<endl;
  int l=v.size();
  int start=0,en=l-1;
  int mid=0;
  while (start<en)
  {
     mid=start+(en-start)/2;
    if (x<v[mid])en=mid-1;
    else if (x>v[mid])start=mid+1;
    else return mid;
  }
  cout<<"Ends----"<<endl;
  return -1;
}

vector<int> Fibonacci_series(int l){
  vector<int> vin;
  int f0=0,f1=1,f3=f0+f1;
  while (f3<l)
  {
    /* code */
    f0=f1;
    f1=f3;
    f3=f0+f1;

  }
  
  vin.push_back(f0);
  vin.push_back(f1);
  vin.push_back(f3);
  return vin;
}

int Fibonacci_Search(vector<int> v,int x){
  int l=v.size();
  vector<int> fibo=Fibonacci_series(l);
  int offset=-1;
  int i=min(offset + fibo[0],x-1);
  if (v[i]<x){
    fibo[2]=fibo[0];
    fibo[0]=fibo[1];
    fibo[1]=fibo[2]-fibo[1];
    offset=i;
  }
  else if (v[i]>x){
    fibo[2]=fibo[1];
    fibo[0]=fibo[0]-fibo[1];
    fibo[1]=fibo[2]-fibo[0];
  }
  else return i;

  if (fibo[0] && v[offset+1] ==x)return offset+1;
  return -1;
}

int main(){
  int n;
  cout<<"Enter number of elements in array"<<endl;
  cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    v.push_back(x);
  }
  int x;
  cout<<"Enter element to be searched"<<endl;
  cin>>x;
  cout<<Fibonacci_Search( v, x);
 
  return 0;  
}
