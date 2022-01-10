//C++ program to find out and display the size of a given file using file pointer function
//Harshwardhan Atkare
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    
    ifstream in;
    in.open("assg3.txt");
    in.seekg(0,ios::end);
    int p=in.tellg();
    in.seekg(0,ios::beg);
    if (!in){
        cout<<"Error while reading file"<<endl;
        return 1;
    }
    int c=0;
    char data[80];
    vector<string> v;

    while (in.getline(data,80))
    {
        v.push_back(data);
    }
    
    for(int j=0;j<v.size();j++){
       for(int i=0;i<v[j].length();i++){
        if (v[j][i]=='.' || v[j][i]=='!' || v[j][i]=='?'){
            c++;
        }
    }
    }
    cout<<(p-2*c);
    in.close();
    return 0;
}