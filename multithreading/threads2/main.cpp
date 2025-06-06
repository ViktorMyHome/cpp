#include <iostream>
#include <list>
#include <thread>
#include <mutex>

#define MAX(a,b) (a)>(b)?1:0


std::mutex g_Mutex;
using namespace std;



int main(){
    int a=3;
    int b=4;
    if(a>b)
        cout<<"true\n";
    else
        cout<<"false\n";

    


return 0;
}
