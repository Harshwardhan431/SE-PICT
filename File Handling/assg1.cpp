//C++ program to count number of lines
//Harshwardhan Atkare
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    
    ifstream in;
    in.open("sample.txt");
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
    cout<<(c);
    in.close();
    return 0;
}