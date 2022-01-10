/*
Name :-Harshwardhan Atkare
Roll No 21106

Write a C++ program to have a class that represents an integer vector and define following functions to perform vector operations :

1.Initialize the vector with zero
2.Overload the >> operator to accept the element of vector
3.Display the vector elements by overloading the << operator
4.Multiply the vector with an integer (i.e. 2* obj)
5.Implementation any other two operations related to vectors (Eg. Inserting element beyond vector size, etc.)
6.To modify the value of a given element
*/

#include<iostream>
using namespace std;

class Vector{

    int size;
    int *p;
    public:
    int currentSize;

    Vector(){
        size=0;
        currentSize=0;
        p=new int[size];
    }

    Vector(int s){
        size=s;
        currentSize=0;
        p=new int[size];
        for(int i=0;i<s;i++){
            *(p+i)=0;
        }
    }

    void push_back(int x){
        if (currentSize==size){
            int tmp[size];

            for(int i=0;i<size;i++){
                tmp[i]=p[i];
            }
            size++;
            currentSize++;
            delete[] p;
            p=new int[size];

            for(int i=0;i<size;i++){
                p[i]=tmp[i];
                if (i==(size-1))p[i]=x;
            }
        }
        else{
            p[currentSize]=x;
            currentSize++;
        }
    }

    int &operator[](int index){
        if (index>=size){
            cout<<"Out of Bound"<<endl;
            exit(0);
        }
        return p[index];
    }

    friend void operator*(int num,Vector &v){
        cout<<" * operator over loading is function is called"<<endl;
        for(int i=0;i<v.size;i++){
            *(v.p+i)=*(v.p+i)*num;
        }
        return ;
    }


    friend istream &operator>>(istream &i,Vector &v){
        for(int j=0;j<v.size;j++)
        {i>>*(v.p+j);
        v.currentSize++;
        }
        return i;
    }

    friend ostream &operator<<(ostream &o,Vector &v){
        for(int j=0;j<v.size;j++)
        o<<*(v.p+j)<<" ";
        cout<<endl;
        return o;
    }

    

    int pop(){
        int t;
        t=p[currentSize-1];
        p[currentSize-1]=0;
        currentSize--;
        return t;
    }

    ~Vector(){
        delete[] p;
    }

};

int main(){

    Vector v(5);
    cout<<"Enter values of the vectors"<<endl;
   
       cin>>v;
       //cout<<v.currentSize++<<endl;
       cout<<"Intial Values"<<endl;
       cout<<v<<endl;
       cout<<"Overloaded values"<<endl;
       3*v;
       cout<<v<<endl;
//cout<<v.currentSize<<endl;
  v.push_back(20);
   cout<<v[v.currentSize-1]<<endl;
   v.pop();
   cout<<v[v.currentSize-1]<<endl;
   //cout<<v[6];
    return 0;
}