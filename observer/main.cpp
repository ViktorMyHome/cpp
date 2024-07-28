#include "Observer.h"
#include "Observable.h"
#include <iostream>
using namespace std;


// class Person : public Observable<Person>
// {//Observable
// 	int age;
// public:
// 	Person(int a){
// 		age = a;
// 	}
// 	int get_age() const
// 	{
// 		return age;
// 	}
// 	void set_age(int age)
// 	{
// 		if(this->age == age) return;
// 		this->age = age;
// 		notify(*this, "age");
// 	}
// };

// struct ConsolePersonObserver: public Observer<Person>
// {
// 	private:
// 		void field_changed(Person &source, const std::string &field_name) override
// 		{
// 			cout<<"Persons "<<field_name<<" has changed to";
// 			if(field_name == "age") cout<<source.get_age();
// 			cout<<endl;
// 		}
// };



int main() {

    GroupChat chat;

    Friend friend1("Alice");
    Friend friend2("Bob");
    Friend friend3("Charlie");

    chat.subscribe(&friend1);
    chat.subscribe(&friend2);
    chat.subscribe(&friend3);

    chat.sendMessage("Hey everyone, let's plan our trip!");

    return 0;
}



