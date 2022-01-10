/*
Name : Harshwardhan Atkare
Roll No : 21106
Write C++ program using STL for sorting and searching user defined 
records such as personal records (Name, DOB, Telephone number etc)
 using vector container.
*/

#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:
    string name;
    int code;

    void getData()
    {
        cout<<"Enter the name of the item"<<endl;
        cin>>name;
        cout<<"Enter the code of the item"<<endl;
        cin>>code;
    }

    int operator==(const Item &o)
    {
        if (code==o.code){
            return 1;
        }else{
            return 0;
        }
    }

};
void Print(Item &o)
    {
        cout<<o.name<<endl;
        cout<<o.code<<endl;
    }

bool sort_func(Item &i, Item &j){
    return i.code < j.code;
}

int main()
{
    vector<Item> v;
    Item i1,i2;
    i1.getData();
    i2.getData();
    v.push_back(i1);
    v.push_back(i2);


    for_each(v.begin(),v.end(),Print);

    Item tmp;
    cout<<"Enter name "<<endl;
    cin>>tmp.name;
    cout<<"Enter code "<<endl;
    cin>>tmp.code;
    vector<Item>::iterator p;
    p=find(v.begin(),v.end(),tmp);
    //Print(*p);
   // p=find(v.begin(),v.end(),tmp);

    if (p==v.end()){
        cout<<"Not found"<<endl;
    }else{
        int indx=p-v.begin();
        cout<<"Code found at index "<<indx<<endl;
    }
    sort(v.begin(),v.end(),sort_func);
    return 0;
}