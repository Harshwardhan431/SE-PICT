#include <iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

const int SIZE = 29;

class HashEntry{
    string word,meaning;
    HashEntry *next;
public:
    HashEntry(){
        word = meaning = "";
        next = nullptr;
    }

    HashEntry(string w,string m){
        word = w;
        meaning = m;
        next = nullptr;
    }
    friend class Dictionary;
};

class Dictionary{
    HashEntry* ht[SIZE];
public:
    Dictionary(){
        for(int i = 0;i < SIZE;i++)
            ht[i] = nullptr;
    }

    int HashFunc(string word){
        int res = 0;
        for(int i = 0;i < (int)word.length();i++){
            res += (word[i] - 'a')*i;
        }
        return res%SIZE;
    }

    void insert(string w,string m){
        HashEntry* new1 = new HashEntry(w,m);
        int hi = HashFunc(w);

        if(ht[hi] == nullptr){  
            ht[hi] = new1;
            return;
        }
        HashEntry* curr = ht[hi];
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new1;
    }

    void display(){
        for(int i = 0;i < SIZE;i++){
            if(ht[i]){
                HashEntry *curr = ht[i];
                cout << i << ": ";
                while(curr){
                    cout << "(" << curr->word << "," << curr->meaning << ") ->";
                    curr = curr->next;
                }
                cout << "\n";
            }
        }
    }

    void search(string key,int &cnt){
        int hi = HashFunc(key);
        cnt = -1;
        if(ht[hi] == nullptr){
            return;
        }

        HashEntry *curr = ht[hi];
        cnt = 0;
        while(curr != nullptr){
            cnt++;
            if(curr->word == key){
                return;
            }
            curr = curr->next;
        }
        cnt = -1;
        return;
    }

    void find(string w){
        int c;
        search(w,c);
        if(c == -1){
            cout << "Element " << w <<" not found in the dictionary" << "\n";
            return;
        }
        cout << "Element " << w << " found in the dictionary :- " << "\n";
        cout << "Word :- " << w << " Comparisions :- " << c << "\n";
        return;
    }

    void remove(string w){
        int c;
        search(w,c);
        
        if(c == -1){
            cout << "Element " << w <<" not found in the dictionary" << "\n";
            return;
        }

        int hi = HashFunc(w);
        HashEntry *curr = ht[hi],*prev = nullptr;
        
        if(c == 1){
            ht[hi] = curr->next;
            delete curr;
            cout << "Deletion successfull" << "\n";
            return;
        }

        while(curr->word != w){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        cout << "Deletion successfull" << "\n";

        return;
    }

};

int main() {

    Dictionary obj;
    obj.insert("abc","1");
    obj.insert("bcd","2");
    obj.insert("cde","3");
    obj.insert("def","4");
    obj.insert("efg","5");
    obj.insert("abc","6");
    obj.insert("def","7");
    obj.find("abc");
    obj.find("efg");
    obj.display();
    obj.remove("abc");
    obj.remove("abc");
    obj.remove("xyz");
    obj.display();

    return 0;
}
