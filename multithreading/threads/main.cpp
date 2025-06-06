#include <iostream>
#include <list>
#include <thread>
#include <mutex>

std::list<int> g_Data;
const int SIZE = 500000;
std::mutex g_Mutex;

void Download() {
    std::cout<<"Start downloading"<<std::endl;
    for(int i=0;i<SIZE;i++) {
        g_Data.push_back(i);
    }
    std::cout<<"Finish downloading"<<std::endl;
}

void Download1() {
    for(int i=0;i<SIZE;i++){
        g_Mutex.lock();
        g_Data.push_back(i);
        g_Mutex.unlock();
    }
}

void Download2() {
    for(int i=0;i<SIZE;i++){
        g_Mutex.lock();
        g_Data.push_back(i);
        g_Mutex.unlock();
    }
}


//g++ main.cpp -o main -lpthread
int main() {
    std::cout<<"Start"<<std::endl;
    std::thread t1;
    std::cout<<" joinable "<<t1.joinable()<<std::endl;
    t1 = std::thread{Download1};
    std::cout<<" joinable "<<t1.joinable()<<std::endl;
    //std::thread thDownloader1(Download1);
    std::thread thDownloader2(Download2);
    auto id = thDownloader2.get_id();

    t1.join();
    thDownloader2.join();

    std::cout<<id<<std::endl;

    //thDownloader.detach();
    std::cout<<g_Data.size()<<std::endl;
    //thDownloader.join();
}