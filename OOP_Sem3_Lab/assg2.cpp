/*Develop a program in C++ to create a database of student’s information system containing
 the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, 
 Contact address, Telephone number, Driving license no. and other. Construct the database
  with suitable member functions. Make use of constructor, default constructor
  , copy constructor, destructor, static member functions, friend class, this pointer,
   inline code and dynamic memory allocation operators-new and delete as well as exception handling.*/

//Harshwardhan Atkare
//21106

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

static  int counter=0;

class Student{
    char *name;
    char *rollno;
    char *classno;
    char *div;
    char *dob;
    char *bloodgrp;
    char *address;
    char *telenumber;
    char *drivingno;
    public:
    friend class Result;
    Student(){
        //Default Constructor
        this->name=new char;
        this->rollno=new char;
        this->classno=new char;
        this->div=new char;
        this->dob=new char;
        this->bloodgrp=new char;
        this->address=new char;
        this->telenumber=new char;
        this->drivingno=new char;
    }
    Student(Student &);//copy constructed
    Student(char *name,char *rollno,char *classno,char *div,char *dob,char *bloodgrp,char *address,char *telephone,char *drivingno);
    ~Student();
    friend istream &operator>>(istream &in,Student &o);
    friend ostream &operator<<(ostream &out,Student &obj);
    void getData();
    
    static void getCount();
};

void Student::getCount(){
    counter+=1;
    cout<<"The current count of object is :"<<counter<<endl;
}

inline void Student::getData(){
    cout<<"Enter name"<<endl;
    cin>>this->name;
    cout<<"Enter roll no"<<endl;
    cin>>this->rollno;
    cout<<"Enter class no"<<endl;
    cin>>this->classno;
    cout<<"Enter div"<<endl;
    cin>>this->div;
    cout<<"Enter dob"<<endl;
    cin>>dob;
    cout<<"Enter blood grp"<<endl;
    try {
        cin>>bloodgrp;
        if (strcmp(bloodgrp,"A+")!=0){throw bloodgrp;}
        if (strcmp(bloodgrp,"B+")!=0){throw bloodgrp;}
        if (strcmp(bloodgrp,"AB+")!=0){throw bloodgrp;}
        if (strcmp(bloodgrp,"A-")!=0){throw bloodgrp;}
        if (strcmp(bloodgrp,"B-")!=0){throw bloodgrp;}
        if (strcmp(bloodgrp,"AB-")!=0){throw bloodgrp;}
        if (strcmp(bloodgrp,"O-")!=0){throw bloodgrp;}
    }
    catch(char *bloodgrp){
        cout<<"Enter valid bloodgrp"<<endl;
    }
    cout<<"Enter address"<<endl;
    cin>>this->address;
    cout<<"Enter telehone no"<<endl;
    cin>>telenumber;
    cout<<"Enter driving no"<<endl;
    cin>>drivingno;
}

Student::Student(char *name,char *rollno,char *classno,char *div,char *dob,char *bloodgrp,char *address,char *telephone,char *drivingno){
        //Parametised Constructor
        int length=strlen(name);
        this->name=new char[length];
        this->name=name;

        length=strlen(rollno);
        this->rollno=new char[length];
        this->rollno=rollno;

        length=strlen(classno);
        this->classno=new char[length];
        this->classno=classno;

        length=strlen(div);
        this->div=new char[length];
        this->div=div;

        length=strlen(dob);
        this->dob=new char[length];
        this->dob=dob;

        length=strlen(bloodgrp);
        this->bloodgrp=new char[length];
        this->bloodgrp=bloodgrp;

        length=strlen(address);
        this->address=new char[length];
        this->address=address;

        length=strlen(telenumber);
        this->telenumber=new char[length];
        this->telenumber=telenumber;

        length=strlen(drivingno);
        this->drivingno=new char[length];
        this->drivingno=drivingno;

    }

    Student::Student(Student &s){
        //copy constructor
        name=s.name;
        rollno=s.rollno;
        classno=s.classno;
        div=s.div;
        dob=s.dob;
        bloodgrp=s.bloodgrp;
        address=s.address;
        telenumber=s.telenumber;
        drivingno=s.drivingno;
    }

    istream& operator>>(istream &in,Student &o){
        cout<<"istream operator is called"<<endl;
        cout<<"Enter name"<<endl;
        in>>o.name;
        cout<<"Enter roll no"<<endl;
        in>>o.rollno;
        cout<<"Enter class no"<<endl;
        in>>o.classno;
        cout<<"Enter division"<<endl;
        in>>o.div;
        cout<<"Enter dob"<<endl;
        in>>o.dob;
        cout<<"Enter blood grp"<<endl;
        in>>o.bloodgrp;
        cout<<"Enter Address"<<endl;
        in>>o.address;
        cout<<"Enter telephone number"<<endl;
        in>>o.telenumber;
        cout<<"Enter driving number"<<endl;
        in>>o.drivingno;
        return in;
    }

    ostream &operator<<(ostream &out,Student & obj){
        cout<<"ostream operator is called"<<endl;
        cout<<"Name";
        out<<obj.name<<endl;
        cout<<"Roll no";
        out<<obj.rollno<<endl;
        cout<<"Class No";
        out<<obj.classno<<endl;
        cout<<"Division";
        out<<obj.div<<endl;
        cout<<"Date of Birth";
        out<<obj.dob<<endl;
        cout<<"Blood Grp";
        out<<obj.bloodgrp<<endl;
        cout<<"Address";
        out<<obj.address<<endl;
        cout<<"Telephone";
        out<<obj.telenumber<<endl;
        cout<<"Driving No";
        out<<obj.drivingno<<endl;
        return out;
    }

    Student::~Student(){
        delete name;
        delete rollno;
        delete classno;
        delete div;
        delete dob;
        delete bloodgrp;
        delete address;
        delete telenumber;
        delete drivingno;
    }


class Result{
    float marks;
    float totalmarks;
public:
    Result(){marks=0;totalmarks=0;}
    friend istream& operator>>(istream &in,Result &r){
        cout<<"Enter marks"<<endl;
        in>>r.marks;
        cout<<"Enter total marks"<<endl;
        in>>r.totalmarks;
        return in;
    }
    void calpercentage(Student &o){
        float per;
        per=(marks/totalmarks)*100;
        cout<<"Roll no: "<<o.rollno<<" has "<<per<<"%"<<endl;
    }

};


int main(){
    Student s;
    char *name=new char;
    char *rollno=new char;
    char *classno=new char;
    char *div=new char;
    char *dob=new char;
    char *bloodgrp=new char;
    char *address=new char;
    char *telenumber=new char;
    char *drivingno=new char;
    cout<<"Enter Name of student"<<endl;
    cin>>name;
    cout<<"Enter roll no"<<endl;
    cin>>rollno;
    cout<<"Enter class no"<<endl;
    cin>>classno;
    cout<<"Enter division"<<endl;
    cin>>div;
    cout<<"Enter dob"<<endl;
    cin>>dob;
    cout<<"Enter blood grp"<<endl;
    cin>>bloodgrp;
    cout<<"Enter address"<<endl;
    cin>>address;
    cout<<"Enter telephone number"<<endl;
    cin>>telenumber;
    cout<<"Enter driving licience number"<<endl;
    cin>>drivingno;
    Student s1;
    cin>>s1;
    cout<<s1;
    Student s3;
    s3.getData();
    cout<<s3;
    Result r;
    cin>>r;
    r.calpercentage(s3);
    s3.getCount();
    return 0;
}