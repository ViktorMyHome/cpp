#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
using namespace std;

// Unordered_map is an associated container that stores elements by the combination
// of a key and mapped value. Internally is implemented using Hash Table
// Cost of search, insert, delete is O(1)
// unordered_map<int, string> umap
// Unordered_set is an associated container implemented using a hash table.
// It contains a key of any type.
// unordered_set<data_type> name
// hash class is default constructible class (functor) thet provides
// the default hash function used by STL
// hash<string> h; string s; h(s);
// Containers:
// 1. Sequences: vector, list, queue, stack, array
// 2. Associative Ordered: map, set, multimap, multiset
// 3. Associative Unordered: unordered_map, unordered_set

int count_unique_substring(const string& str){
    hash<string> h;
    set<string> ms;
    set<int> msi;
    for(int i=0; i<str.size(); ++i){
        for(int j=i;j<str.size(); ++j){
            ms.insert(str.substr(i,j));
            msi.insert(h(str.substr(i,j)));
        }
    }
    set<string>::iterator it;
    set<int>::iterator iti;
    int count=0;
    int prev = 0;
    for(it = ms.begin(), iti = msi.begin(); it!=ms.end(); ++it, ++iti){
        cout<<*it<<" "<<*iti<<endl;
        if(prev!=*iti){
            count++;
        }
        prev = *iti;
    }
    return count;
}

//try to use .count(str)
int count_substring_match(const string& str1, const string& str2){
    hash<string> h;
    set<string> ms1;
    set<int> msi1;
    set<string> ms2;
    set<int> msi2;
    multiset<int> sum;

    for(int i=0; i<str1.size(); ++i){
        for(int j=i;j<str1.size(); ++j){
            ms1.insert(str1.substr(i,j));
            msi1.insert(h(str1.substr(i,j)));
        }
    }

    for(int i=0; i<str2.size(); ++i){
        for(int j=i;j<str2.size(); ++j){
            ms2.insert(str2.substr(i,j));
            msi2.insert(h(str2.substr(i,j)));
        }
    }

    set<int>::iterator iti;
    for(iti = msi1.begin(); iti!=msi1.end(); ++iti){
        sum.insert(*iti);
    }
    for(iti = msi1.begin(); iti!=msi1.end(); ++iti){
        sum.insert(*iti);
    }

    multiset<int>::iterator itii;
    int count=0;
    int prev = 0;
    for(itii = sum.begin(); itii!= sum.end(); ++itii){
        cout<<*itii<<" "<<*iti<<endl;
        if(prev==*itii){
            count++;
        }
        prev = *itii;
    }
    return count;
}

string convert_string(const string& str){
    stack<char> sch;
    for(int i=0; i<str.size(); i++){
        sch.push(str[i]);
    }
    string out{""};
    for(int i=0; i<str.size(); i++){
        out+=sch.top();
        sch.pop();
    }   
    //out+='\0';
    return out;
}

int quantity_of_anagrams(const string& str){
    stack<string> st;
    hash<string> h;
    unordered_set<string> s1;
    unordered_set<string> s2;
    for(int i=0; i<str.size(); ++i){
        for(int len=1; len<=str.size()-i; ++len){
            s1.insert(str.substr(i,len));
            s2.insert(convert_string(str.substr(i,len)));
        }
    }

    unordered_set<string>:: iterator it1;
    unordered_set<string>:: iterator it2;
    for(it1 = s1.begin();it1!=s1.end(); ++it1)
    cout<<*it1<<" ";
    cout<<endl;
    for(it2 = s2.begin();it2!=s2.end(); ++it2)
    cout<<*it2<<" ";
    cout<<endl;

    int count=0;
    it2 = s2.begin();
    for(it1 = s1.begin(); it1!=s1.end(); ++it1){
        cout<<*it1<<" ";
        it2 = s2.find(*it1);
        if(it2!=s2.end())
            count++;
    }
    cout<<endl;
    return count;
}


int main(){

//    cout<<count_unique_substring("aaab")<<endl;
//    cout<<count_substring_match("aabac", "ba")<<endl;
cout<<quantity_of_anagrams("aaabbad")<<endl;

    unordered_set<string> sampleSet = { "geeks1", "for", "geeks2" }; 

    // use of find() function 
    if (sampleSet.find("geeks1") != sampleSet.end()) { 
        cout << "element found." << endl; 
    } 
    else { 
        cout << "element not found" << endl; 
    } 

    return 0;
}
