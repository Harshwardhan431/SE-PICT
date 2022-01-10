#include <iostream>
#include <string>
using namespace std;

class User
{
    int age;
    long long int income;
    string city;
    char vehicle;

    public:
        void getdetails(){
            cout<<"Enter age"<<endl;
            cin>>age;
            cout<<"Enter income"<<endl;
            cin>>income;
            cout<<"Enter city"<<endl;
            cin>>city;
            cout<<"Enter four-wheeler/two-wheeler (2/4)"<<endl;
            cin>>vehicle;

            try{
                 if(age<18 || age>55){
                    throw age;
                }
            }catch(int age){
                cout<<"Invalid age"<<endl;
            }

            try{
                  if(income<50000 || income>100000){
                    throw income;
                }
            }catch(long long int income){
                cout<<"Invalid income"<<endl;
            }

            try{
                if(city!="Pune" || city!="Mumbai" || city!="Banglore" || city!="Chennai"){
                    throw city;
                }
            }catch(string city){
                cout<<"Invalid city"<<endl;
            }

            try{
                if(vehicle=='2'){
                    throw vehicle;
                }
            }catch(int vechile){
                cout<<"Invalid vechile"<<endl;
            }

        }

        void display(){
            cout<<age<<endl;
            cout<<income<<endl;
            cout<<city<<endl;
            cout<<vehicle<<endl;
        }
};

int main()
{
    User u;
    u.getdetails();
    u.display();
}