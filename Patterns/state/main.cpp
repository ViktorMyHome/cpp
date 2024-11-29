#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct LightSwitch;

struct state
{
    virtual void on(LightSwitch* lhs)
    {
        cout<<"Light is already on\n";
    }
    virtual void off(LightSwitch* lhs)
    {
        cout<<"Light is already off\n";
    }
};

struct onstate : state
{
    onstate()
    {
        std::cout<<"Light is turned on\n";
    }
    void off(LightSwitch *lhs) override;
};


struct offstate:state
{
    offstate()
    {
        std::cout<<"Light is turned off\n";
    }
    void on(LightSwitch *lhs) override;
};

class LightSwitch
{
    state *state_;
    public:
    LightSwitch()
    {
        state_ = new offstate();
    }
    void set_state(state *state)
    {
        this->state_ = state ;
    }
    void on(){
        state_->on(this);
    }
    void off(){
        state_->off(this);
    }
};

void onstate::off(LightSwitch *lhs)
{
    cout<<"switching light off...\n";
    lhs->set_state(new offstate());
    delete this;
}

void offstate::on(LightSwitch *lhs)
{
    cout<<"switching light on...\n";
    lhs->set_state(new onstate());
    delete this;
}

int main(){

LightSwitch ls;
    ls.on();
    ls.off();
    ls.off();
return 0;
}