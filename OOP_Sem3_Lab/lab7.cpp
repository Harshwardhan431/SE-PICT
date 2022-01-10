
/*
Write a C++ program that creates an output file, writes information to it , 
closes the file , open it again as an input file and read the info from the file
*/
#include<iostream>
#include<fstream>
using namespace std;
class Lab7{

private:
  string name;
  int rollno;
public:
  void takedetails(){
      ofstream out;
      out.open("lab7.txt");
      cout<<"Enter your name"<<endl;
      cin>>name;
      cout<<"Enter roll no "<<endl;
      cin>>rollno;
      out<<"My name is "<<name<<" and my roll number is "<<rollno<<endl;
      out.close();
  }

  void getdetails(){
      ifstream in;
      in.open("lab7.txt");
      string st;
      while (in.eof()==0){
        getline(in,st);
        cout<<st<<endl;
      }
      in.close();
  }
    
};

int main(){
    Lab7 l;
    l.takedetails();
    l.getdetails();
    return 0;
}