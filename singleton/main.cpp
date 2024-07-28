#include "Observer.h"
#include "Observable.h"
#include <iostream>
#include <map>
#include <fstream>
using namespace std;


class SingletonDataBase{
    static SingletonDataBase * instance;

    SingletonDataBase(){
        cout<<"Initialization database"<<endl;
        ifstream ifs("capitals.txt");
        string s, s2;
        while(getline(ifs,s)){
            getline(ifs,s2);
            cout<<s2<<endl;
        }
    }
    ~SingletonDataBase(){
        cout<<"buy"<<endl;
    }
public:
    std::map<string, int>capitals;
    SingletonDataBase(SingletonDataBase const&) = delete;
    void operator=(SingletonDataBase const&) = delete;

    static SingletonDataBase * get()
    {
        if(instance == nullptr)
            instance = new SingletonDataBase();
        return instance;
    }
};

SingletonDataBase * SingletonDataBase::instance = nullptr;

int main() {
    SingletonDataBase * singleton =  SingletonDataBase::get();


    return 0;
}



