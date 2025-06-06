#include <iostream>
#include <string.h>
#include <unistd.h>
#include "zmq.h"
using namespace std;






int main() {

    void* context = zmq_ctx_new();
    void* respond = zmq_socket(context, ZMQ_REP);// create new context
    // ZMQ_REP socket is used by a client to send requests to and receive replies from a sever

    zmq_bind(respond, "tcp://*:5555");
    printf("server starting...\n");

    for(;;){
        zmq_msg_t request;


        zmq_msg_init(&request);
        zmq_msg_recv(&request, respond, 0);
        printf("Received: \n");
        zmq_msg_close(&request);
        sleep(1);// sleep 1 second
        zmq_msg_t reply;
        zmq_msg_init_size(&reply, strlen("world"));
        memcpy(zmq_msg_data(&reply), "world", 5);
        zmq_msg_send(&reply, respond, 0);
        zmq_msg_close(&reply);
    }

    zmq_close(respond);
    zmq_ctx_destroy(context);

    return 0;
}
