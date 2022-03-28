//Hashing

#include<iostream>
using namespace std;

const int n=10;

struct data
{
    int n;
    string name;
    public:
    data(){
         n=0;
         name="";
    }
    friend class HashTable;
};

class HashTable
{
    data hasharr[n];
    public:
    int getCode(int x){
        return x%n;
    }

    int count(int key){
    	int ind=getCode(key);
    	        int i=0;
    	        while (hasharr[(ind+i)%n].n!=key)
    	        {
    	            i++;}
    	        return (i+1);
    }

    void serach(int key){
        int ind=getCode(key);
        int i=0;
        while (hasharr[(ind+i)%n].n!=key)
        {
            i++;        }
        cout<<"The value at "<<key<<" is "<<hasharr[(ind+i)%n].name<<endl;

    }
    int comp(int key){
        int ind=getCode(key);
        int i=0;
        while (hasharr[(ind+i)%n].n!=key)
        {
            i++;        }
        return i;

    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<"Key "<<hasharr[i].n<<" has "<<hasharr[i].name<<" value"<<endl;
        }
    }
    int probe(int key){
        int ind=getCode(key);
        int i=0;
        while (hasharr[(i+ind)%n].n!=0)
        {
            i++;
        }
        return (i+ind)%n;
    }

    void insert(int x,string si){
        int index=getCode(x);
        if (hasharr[index].n!=0){
            index=probe(x);
        }
        hasharr[index].n=x;
        hasharr[index].name=si;
    }

    void insertWR(int x,string s){
    	int index=getCode(x);
    	if (hasharr[index].n==0){
            hasharr[index].n=x;
            hasharr[index].name=s;
    	}else if (index==getCode(hasharr[index].n)){
    		index=probe(x);
    		 hasharr[index].n=x;
    		 hasharr[index].name=s;
    	}else{
    		string ts=hasharr[index].name;
    		int t=hasharr[index].n;
    		hasharr[index].n=x;
    		hasharr[index].name=s;
    		index=probe(t);
    		hasharr[index].n=t;
    		hasharr[index].name=ts;

    	}
    }

    void del(int key){
    	int ind=getCode(key);
    	hasharr[ind].n=0;
    	hasharr[ind].name="";
    }
};

int main()
{
    HashTable ht;
    while (1)
    {
        int choice;
        cout<<"Enter 1 for Inserting data in Linear Probing without Replcement"<<endl;
        cout<<"Enter 2 for searching a value "<<endl;
        cout<<"Enter 3 for display"<<endl;
        cout<<"Enter 4 for Inserting data in Linear Probing with Replcement"<<endl;
        cout<<"Enter 5 to delete an element from the hashtable"<<endl;
        cout<<"Enter 6 to check number of comparsion"<<endl;
        cout<<"Enter 7 to count the number of comp"<<endl;
        cout<<"Enter -1 for exit"<<endl;
        cin>>choice;
        if (choice==1){
            int k;
            cout<<"Enter key to be inserted"<<endl;
            cin>>k;
            string s;
            cout<<"Enter the phone number of "<<k<<" th key"<<endl;
            cin>>s;
            ht.insert(k,s);
        }else if (choice==2){
            int k;
            cout<<"Enter the key to be seached"<<endl;
            cin>>k;
            ht.serach(k);
        }else if (choice==3){
            ht.display();
        }else if (choice==4){
        	int k;
        	cout<<"Enter key to be inserted"<<endl;
        	cin>>k;
        	string s;
        	cout<<"Enter the phone number of "<<k<<" th key"<<endl;
        	cin>>s;
        	ht.insertWR(k, s);
        }else if (choice==5){
        	cout<<"Enter the key to be deleted"<<endl;
        	int x;cin>>x;
        	ht.del(x);
        }else if (choice==6){
            cout<<"Enter the key you want to check comparsion"<<endl;
            int k;cin>>k;
            cout<<"Comparsion are "<<ht.comp(k)<<endl;
        }else if (choice==7){
        	int k;
        	cout<<"Enter the key to see the number of comp"<<endl;
        	cin>>k;
        	cout<<"Comparsion "<<ht.count(k)<<endl;
        }
        else if (choice==-1){
            break;
        }
    }
    return 0;
}
