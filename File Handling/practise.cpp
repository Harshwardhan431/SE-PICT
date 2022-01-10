/*
Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.
*/

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    /*ofstream out;
    out.open("sample.txt");
    string s;
    cout<<"Enter name "<<endl;
    cin>>s;
    out<<"My name is "<<s<<endl;
    out.close();*/

    ifstream in;
    in.open("sample.txt");
    string s1;
    while (in.eof()==0)
    {
        getline(in,s1);
        cout<<s1<<endl;
    }
    in.close();
    return 0;
}