/*
Name : Harshwardhan Atkare
Roll No : 21106

WAP to create generic class using templates
tp perform array opeartion applicable to data type like float,int and double
Opeartions : - 1) Inserting
               2)Deleting specific element
               3)Addtion of 2 arrrays using opeartor overloading
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

template<class T>
class Generic
{
    T n;
    T *a;
    public:
    Generic(){
        n=0;
        for(T i=0;i<n;i++){
            *(a+i)=0;
        }
    }
    
    Generic(T n)
    {
        this->n=n;
         a=new T[n];
         for(T i=0;i<n;i++){
            *(a+i)=0;
        }
    }
    void Inserting(T k,T pos);
    void Delete(T k);
    void Display(T n);
    friend Generic operator+(Generic g1,Generic g2);
};

template<class T>
Generic<T> operator+(Generic<T> g1,Generic<T> g2)
{
    Generic<T> g(max(g1.n,g2.n));
    for(int i=0;i<max(g1.n,g2.n);i++){
        *(g.a+i)=*(g1.a+i)+*(g2.a+i);
    }
    return g;
}

template<class T>
void Generic<T>::Display(T n)
{
    for(int i=0;i<n;i++)
        {
            cout<<*(a+i)<<" ";
        }
        cout<<endl;
}

template<class T>
void Generic<T>::Inserting(T k,T pos)
{
    for(T i=n;i>pos;i--){
        *(a+i)=*(a+i-1);
    }
    *(a+pos)=k;
    n++;
}

template<class T>
void Generic<T>::Delete(T ind)
{
    T x=*(a+ind);
    for(T i=ind;i<n;i++){
        *(a+i)=*(a+i+1);
    }
    n--;
}

int main()
{
    int n1,n2;
    cout<<"Enter number of elements in the 1st array"<<endl;
    cin>>n1;
    cout<<"Enter number of elements in the 2nd array"<<endl;
    cin>>n2;
    Generic<int> g1(n1);
    for(int i=0;i<n1;i++)
    {
        cout<<"Enter "<<(i+1)<<" th element of first array "<<endl;
        int x;cin>>x;
        g1.Inserting(x,i);
    }
    Generic<int> g2(n2);
    for(int i=0;i<n2;i++)
    {
        cout<<"Enter "<<(i+1)<<" th element of second array "<<endl;
        int x;cin>>x;
        g2.Inserting(x,i);
    }
    int h1,h2;
    cout<<"Do you want to delete any of the first array element? put 1 or 0 "<<endl;
    cin>>h1;
    if (h1==1)
   {
        cout<<"Enter the index at which element is to be deleted "<<endl;
    int ind;cin>>ind;
    g1.Delete(ind-1);
    n1--;
   }
   cout<<"Do you want to delete any of the first array element? put 1 or 0 "<<endl;
    cin>>h2;
    if (h2==1)
   {
        cout<<"Enter the index at which element is to be deleted "<<endl;
    int ind;cin>>ind;
    g2.Delete(ind-1);
    n2--;
   }
   Generic<int> g3(max(n1,n2));
   g3=g1+g2;
   cout<<"The 1st array elemnts are "<<endl;
   g1.Display(n1);
   cout<<"The 2nd array elements are "<<endl;
   g2.Display(n2);
   cout<<"The sum of both array elemnts are "<<endl;
   g3.Display(max(n1,n2));
    
    return 0;
}
