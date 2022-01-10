/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overloaded operator+ to add two complex numbers.
3.	Overloaded operator* to multiply two complex numbers.
4.	Overloaded << and >> to print and read complex Numbers.

*/

#include<iostream>
using namespace std;

class Complex{

    float real,img;
    public:

    Complex(){
        real=0.0;img=0.0;
    }

    Complex operator+(Complex c){

        Complex temp;
        temp.real=c.real+real;
        temp.img=c.img+img;
        return temp;
    }

    Complex operator*(Complex c){
        Complex temp;
        temp.real=(real * c.real ) - (img*c.img);
        temp.img=(real*c.img) + (img*c.real);
        return temp;
    }

    friend istream &operator>>(istream &i,Complex &s){
        cout<<"Enter the real part"<<endl;
        i>>s.real;
        cout<<"Enter img part "<<endl;
        i>>s.img;
        return i;
    }

    friend ostream &operator<<(ostream &o,Complex &s){
        o<<s.real<<" + "<<s.img<<"i"<<endl;
        return o;
    }

};

int main(){

    Complex c1,c2,c3,c4;
    cin>>c1;
    cin>>c2;
    c3=c1+c2;
    c4=c1*c2;
    cout<<"Addition of two numbers "<<c3<<endl;
    cout<<"Multiplication of two numbers"<<c4<<endl;
    return 0;
}