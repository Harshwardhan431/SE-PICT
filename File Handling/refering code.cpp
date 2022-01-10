#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    //Printing data in txt file
    ofstream out("video2.txt");//making object of ofstream
    cout<<"Enter your name";
    string name;
    cin>>name;//taking name as input 
    out<<"My name is "+name<<endl;//passing inputed name to to the txt file
    out.close();//breaking contact with txt file
    
   cout<<"---------"<<endl;
   
   ifstream hin("video2.txt");
   string cont;
   getline(hin,cont);//hin>>const;
   cout<<"Reading data from video2 file "<<cont<<endl;
   hin.close();
   return 0;
   
}