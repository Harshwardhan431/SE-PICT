/*
Name : Harshwardhan Atkare
Roll No : 21106
Write a program in C++ to use map associative container. The keys will be the names of 
states and the values will be the populations of the states. When the program runs,
the user is prompted to type the name of a state. The program then looks in the map,
using the state name as an index and returns the population of the state.
*/

 #include<map>
 #include<iostream>

 using namespace std;

 int main()
 {
     map<string,int> m;
     int n;
     cout<<"Enter number of states "<<endl;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         int x;string s;
         cout<<"Enter the "<<(i+1)<<" th state name"<<endl;
         cin>>s;
         cout<<"Enter the population in the "<<s<<" state"<<endl;
         cin>>x;
         m.insert({s,x});
     }
     string name;
    cout<<"Enter the name of the state whose you want population "<<endl;
    cout<<"Choice from below :-"<<endl;
    for(auto s:m)
     {
         cout<<s.first<<endl;
     }
     cin>>name;
     map<string,int>::iterator i;
     auto it=m.find(name);
     for(i=m.begin();i!=m.end();++i)
     {
         if ((*i).first==(*it).first){
             cout<<"Population of state "<<(*i).first<<" is "<<(*i).second<<endl;
             break;
         }
     }
     if (i==m.end()){
             cout<<"State not found in the list"<<endl;
         }
     return 0;
 }