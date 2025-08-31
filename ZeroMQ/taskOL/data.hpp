#ifndef DATA_HPP
#define DATA_HPP

#include <string.h>
#include "zmq.h"
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <atomic>
#include <thread>
#include <mutex>
#include <fstream>
#include <iostream>

#define QUANTITY_OF_ELEMENTS 100
    
struct data_to_server_thread{
    double X_;
    uint32_t routing_id_;
};


#endif