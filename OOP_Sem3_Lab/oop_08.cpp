
//  ASSIGNMENT NO -: 08
/*
  Write a function template for selection sort that 
  inputs, sorts and outputs an integer array and a 
  float array
*/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void Sorting_algo()
{
  T ele;
  int size;
  cout << "Enter the array Size" << endl;
  cin >> size;
  T a[size];
  cout << "Enter Element For the Array" << endl;
  for (int m = 0; m < size; m++)
  {
    cin >> ele;
    a[m] = ele;
  }
  cout << "Array WithOut Sorted\n";
  cout << "---->\t[ ";
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
  cout << "]\n";
  for (int i = 0; i < size; i++)
  {
    int min = i;
    int j;
    for (j = i + 1; j < size; j++)
    {
      if (a[min] > a[j])
      {
        min = j;
      }
    }
    int temp;
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
  cout << "Array With Sorted\n";
  cout << "--->\t[ ";
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
  cout << "]\n";
};
int main()
{
  int ch;
  char ans;
  do
  {  cout<< "\n ***  MENU **** \n";
     cout<< "1) Sort the interge Array \n2) Sort he float Array \n3) Exit";
     cout<<endl;
     cout<< "Enter choice  : ";
     cin >> ch;
     cout<<endl;
     switch (ch)
     {
     case 1: Sorting_algo<int>(); 
             break;
     case 2: Sorting_algo<float>();
             break;
     case 0: exit(0);
    
     default: cout<<" Enter valid choice"<<endl;  
             break;
     }
  cout<<" Do you want to continue (y/n) \n";
   cin>> ans;
  } while (ans == 'y');
  
  return 0;
}