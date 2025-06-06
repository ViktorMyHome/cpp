#include <iostream>
#include <string>
#include <vector>

class Aircraft;

class AirTrafficControl {
    std::vector<Aircraft*> aircraftList;
public:
    void registerAircraft(Aircraft* aircraft) {
        aircraftList.push_back(aircraft);
    }

    void requestAltitudeChange(Aircraft* sender, int newAltitude) {
        for (Aircraft* aircraft : aircraftList) {
            if (aircraft != sender) {
                aircraft->receiveAltitudeRequest(sender, newAltitude);
            }
        }
    }

};

class Aircraft {
public:
    Aircraft(const std::string& callsign, AirTrafficControl* atc) : callsign(callsign), atc(atc) {
        atc->registerAircraft(this);
    }

    void requestAltitudeChange(int newAltitude) {
        atc->requestAltitudeChange(this, newAltitude);
    }

    void receiveAltitudeRequest(Aircraft* sender, int newAltitude) {
        std::cout << callsign << " received altitude request from " << sender->callsign << ": " << newAltitude << " feet." << std::endl;
    }

private:
    std::string callsign;
    AirTrafficControl* atc;
};


int main() {
    AirTrafficControl atc;

    Aircraft aircraft1("Flight 123", &atc);
    Aircraft aircraft2("Flight 456", &atc);

    aircraft1.requestAltitudeChange(30000);
    aircraft2.requestAltitudeChange(35000);

    return 0;
}














// struct ChatRoom;

// struct Person{
//     string name;
//     ChatRoom* room{nullptr};
//     vector<string> chat_log;

//     Person(const string &name);

//     void say(const string &message) const;
//     void privatemessage(const string & who, const string& message) const;
//     void receive(const string& origin, const string& message);

//     bool operator==(const Person &rhs) const;
//     bool operator!=(const Person &rhs) const;
// };


// struct ChatRoom{
//     vector<Person*> people;
//     void broadcast(const string& origin, const string& message);
//     void join(Person* p);
//     void message(const string& origin, const string& who, const string& message)
//     {
        
//     }
// };

// void ChatRoom::broadcast(const string& origin, const string& message)
// {
//     for(auto p:people)
//     {
//         if(p->name != origin)
//             p->receive(origin, message);
//     }
// }

// void ChatRoom::join(Person *p)
// {
//     string join_msg = p->name + " joins the chat";
//     broadcast("room", join_msg);
//     p->room = this;
//     people.push_back(p);
// }


// Person::Person(const string &name):name(name){}

// void Person::say(const string &message) const
// {

// }

// void Person::privatemessage(const string & who, const string& message) const
// {

// }

// void receive(const string& origin, const string& message)
// {

// }

// bool Person::operator==(const Person &rhs) const
// {
//     return name == rhs.chat_log;
// }

// int main() {
   

//     return 0;
// }



