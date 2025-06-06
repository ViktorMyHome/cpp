#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <chrono>

using namespace std;

// writer thread modifies a shared string
// reader thread uses the modified string.
// two threads has to be coordinated.

std::mutex mut;
std::condition_variable cv;
std::string sdata;

void reader(){
    // lock the mutex
    std::cout<<" reader thread locking mutex "<<endl;
    std::unique_lock<std::mutex> uniq_lck(mut);
    std::cout<<" reader thread has locked the mutex "<<endl;
    // unlock the mutex and makes this thread sleep until the condition variable wakes up
    std::cout<<" reader thread sleeping..."<<endl;
    cv.wait(uniq_lck);
    // the condition variable wakes this thread up and lock the mutex
    std::cout<<" reader thread wakes up"<<endl;
    std::cout<<" Data is "<<sdata<<endl;
}

void writer()
{
    {
        std::cout<<" writer thread locking mutex "<<endl;
        // lock the mutex
        std::lock_guard<std::mutex> lck_guard(mut);
        std::cout<<" writer thread has locked the mutex "<<endl;
        std::this_thread::sleep_for(chrono::milliseconds(2000));
        // modify the shared data
        sdata = "Populated";
    }   // release the lock
    // notify the condition variable
    std::cout<<" writer thread sends notification "<<endl;
    cv.notify_one();
}


int main(){

    sdata = "Empty";

    cout<<" Data is "<<sdata<<endl;

    std::thread read(reader);
    std::thread write(writer);

    write.join();
    read.join();
    
return 0;
}
