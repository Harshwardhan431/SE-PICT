#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class Student{
	string fname;
public:
	Student(){
		fname = "default.txt";
	}

	void getFile(){
		cout << "Enter file name :- ";
		// cin.ignore();
		getline(cin,fname);
	}

	void getData(){
		string data;
		cout << "Enter data to be inputted in file :- " << "\n";
//		cin.ignore();
		getline(cin,data);

		ofstream fout(fname,ios::out);

		if(fout.is_open()){
			fout << data;
			cout << " !!! Data inserted successfully !!! " << "\n";
			fout.close();
		}
		else{
			cout << " !!! File not opened properly !!! " << "\n";
			return;
		}
	}
	void display(){
		ifstream fin(fname);
		if(fin.is_open()){
			string data;
			while(getline(fin,data)){
				cout << data;
			}
			fin.close();
		}
		else{
			cout << " !!! File not opened properly !!! " << "\n";
		}
	}

	void clearFile(){
		ofstream fout(fname,ios::out | ios::trunc);
		if(fout.is_open()){
			cout << " !!! File data deleted successfully !!! " << "\n";
			fout.close();
		}
		else{
			cout << " !!! File not opened properly !!! " << "\n";
		}
	}

};

int main() {

	Student s;
	s.getFile();
	s.getData();
	s.display();
	cout << "\n";
	s.clearFile();
	s.display();
	cout << "\n";
	return 0;
}