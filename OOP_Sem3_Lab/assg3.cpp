/*
Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.

*/

#include <iostream>
#include <string>
using namespace std;

class Publication
{
    protected:
        string title;
        float price;
};

class Book : private Publication
{
    int pagecount;

    public:
        void setdetails();
        void display();
};

class Tape : private Publication
{
    float play_time;

    public:
        void setdetails();
        void display();
};

void Book :: setdetails()
{
    try
    {
        cout << "Enter the title of the book: " << endl;
        getline(cin,title);
        cout << "Enter the price of the book: " << endl;
        cin >> price;
        cout << "Enter the number of pages in the book: " << endl;
        cin >> pagecount;

        if(title.size()<3){
            throw title;
        }
        if(price<0.0){
            throw price;
        }
        if(pagecount<0){
            throw pagecount;
        }
    }
    catch(string)
    {
        title = "";
        price = 0.0;
        pagecount = 0;
    }
    catch(float)
    {
        title = "";
        price = 0.0;
        pagecount = 0;
    }
    catch(int)
    {
        title = "";
        price = 0.0;
        pagecount = 0;
    }
}

void Book :: display()
{
    cout << "\nDetails of the Book:- " << endl;
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
    cout << "Number of pages: " << pagecount << endl;
}

void Tape :: setdetails()
{
    try
    {
        cout << "Enter the title of the tape: " << endl;
        cin.ignore();
        getline(cin,title);
        cout << "Enter the price of the tape: " << endl;
        cin >> price;
        cout << "Enter the playing time in minutes: " << endl;
        cin >> play_time;

        if(title.size()<3){
            throw title;
        }
        if(price<0.0){
            throw price;
        }
        if(play_time<0.0){
            throw play_time;
        }
    }
    catch(string)
    {
        title = "";
        price = 0.0;
        play_time = 0.0;
    }
    catch(float)
    {
        title = "";
        price = 0.0;
        play_time = 0.0;
    }
}

void Tape :: display()
{
    cout << "\nDetails of the Tape:- " << endl;
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
    cout << "Playing Time: " << play_time << " minutes" << endl;
}

int main()
{
    Book b;
    Tape t;

    b.setdetails();
    t.setdetails();

    b.display();
    t.display();

    return 0;
}