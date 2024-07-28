#pragma once
#include "Observer.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//template <typename> struct Observer;


// template <typename T> class Observable
// {
//     std::vector<Observer<T>*> observers;
//     public:
//     void notify(T& source, const std::string& field_name)
//     {
//         for(auto observer : observers)
//             observer->field_changed(source, field_name);
//     }

//     void subscribe(observer<T>& observer)
//     {
//         observers.push_back(&observer);
//     }

//     void unsibscribe(observer<T>& observer)
//     {
//         observers.erase(
//             remove(observers.begin(), observers.end(), observer), observers.end())
//         );
//     }


// };



// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;
};


// Concrete Subject class
class GroupChat : public Subject {
private:
    vector<Observer*> observers;
    vector<string> messages;
public:
    void subscribe(Observer* observer) override {
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) override {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(messages.back());
        }
    }

    void sendMessage(const string& msg) {
        messages.push_back(msg);
        notify();
    }
};

// Concrete Observer class
class Friend : public Observer {
private:
    string name;
public:
    Friend(const string& n) : name(n) {}

    void update(const string& newMessage) override {
        cout << name << " received a message: " << newMessage << endl;
    }
};
