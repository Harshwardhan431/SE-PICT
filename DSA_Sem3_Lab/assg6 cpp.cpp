/*
Quick sort
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

#include<bits/stdc++.h>
using namespace std;
void harsh(){
    int t;cin>>t;
    while (t--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
    }
}
int partition(int l,int h,int a[]){
    int pivot=a[l];
    int i=l,j=h;
    while(i<j){
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if (i<j)swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}

void QuickSort(int l,int h,int ar[]){
    if (l<h){
        int j=partition(l,h,ar);
        QuickSort(l,j,ar);
        QuickSort(j+1,h,ar);
    }return;
}

int main(){
    int n;cin>>n;
    int ary[n];
    for(int i=0;i<n;i++)cin>>ary[i];
    QuickSort(0,n,ary);
    for(int i=0;i<n;i++)cout<<ary[i]<<" ";
    return 0;
}