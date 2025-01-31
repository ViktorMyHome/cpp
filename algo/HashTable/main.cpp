#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

// Applications of Hash Functions:
// Hash tables - efficient way to store and retrive data. 
// Data Integrity - to ensure the integrity of data by generating checksum
// Cryptography - to create secure hash algorithms like SHA-256
// Data Structures - ?
// Load Factor = Total elements in hash table/size of hash table
// Key - any string or integer which fed as input in the hash function
// Hash function - received the input key and returns the index of an element in an array
// called a hash table. Index is hash index
// Hash table is an array of lists. It stores values corresponding to the keys
// Division method. Dividing the key by a prime number and using the reminder as the hash value
// h(k) = k mod m  Simple, poor distribution
// Mid-Square method - key is squared and the middle digits of the result are taken as the hash value
// good distribution, require more computational efforts.
// Folding method - divide the key into equal parts, calculate the module.

int hash_string(string str, int n){
    int sum = 0;
    for(int i=0;i<(int)str.size();++i)
        sum = sum*26+str[i] - 'a';
    return sum % n;
}

class PhoneEntry{
public:
    const static int INTERNAL_LIMIT = 2147483647;
    string name;
    string phone_number;
    PhoneEntry(string name, string phone):name(name), phone_number(phone){};
    int hash(){
        return hash_string(name, INTERNAL_LIMIT);
    }
    void print(){
        cout<<name<<" "<<phone_number<<endl;
    }
};

class PhoneHashTable{
private:
    int table_size;
    double limit_load_factor;
    vector<vector<PhoneEntry>> table;
public:
    PhoneHashTable(int tableSize=10, double limitLoadFactor=0.75): table_size(tableSize), limit_load_factor(limitLoadFactor){
        table.resize(tableSize);
    }

//table of index
    void put(PhoneEntry phone){
        checkUpdateLoadFactor();
        int idx = phone.hash()%table_size;
        for(int i=0; i<(int)table[idx].size(); ++i){
            if(table[idx][i].name == phone.name){
                table[idx][i] = phone; // exist -> update
                return;
            }
        }
        table[idx].push_back(phone);
    }

    bool remove(PhoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i=0;i<(int)table[idx].size(); ++i){
            if(table[idx][i].name == phone.name){
                // swap with last and remove last in O(1)
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                return true;
            }
        }
        return false;
    }

    bool get(PhoneEntry &phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i<(int)table[idx].size(); ++i){
            if(table[idx][i].name == phone.name){
                phone = table[idx][i];
                return true;
            }
        }
        return false;
    }

    void print_all(){
        for(int hash = 0; hash<table_size; ++hash){
            if(table[hash].size() == 0)
                continue;
            cout<<"Hash "<<hash<<": ";
            for(int i=0;i<(int)table[hash].size(); ++i)
                table[hash][i].print();
            cout<<endl;
        }
    }

    void rehashing(){
        table_size *= 2;
        table.resize(table_size);

    }

    int checkUpdateLoadFactor(){
        while(limit_load_factor > static_cast<double>(table.size()/table_size))
            rehashing();
    }

};


int main(){

    PhoneHashTable table(3);

    table.put(PhoneEntry("mostafa", "604-401-120"));
    table.put(PhoneEntry("mostafa", "604-401-777"));
    table.put(PhoneEntry("ali", "604-401-343"));
    table.put(PhoneEntry("ziad", "604-401-17"));
    table.put(PhoneEntry("hany", "604-401-758"));
    table.put(PhoneEntry("belal", "604-401-550"));
    table.put(PhoneEntry("john", "604-401-223"));

    PhoneEntry e("mostafa", "");
    if(table.get(e));
        cout<<e.phone_number<<endl;

    table.print_all();

    cout<<table.remove(PhoneEntry("smith", ""))<<endl;
    cout<<table.remove(PhoneEntry("hany", ""))<<endl;    

    table.print_all();

    return 0;
}
