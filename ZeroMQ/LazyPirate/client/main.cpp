#include <iostream>
#include <string.h>
#include <unistd.h>
#include "zmq.h"
using namespace std;






int main() {

    void* context = zmq_ctx_new();
    void* request = zmq_socket(context, ZMQ_REQ);// create new context
    zmq_connect(request, "tcp://localhost:5555");
    printf("client starting...\n");
    int count = 0;


    for(;;){
        zmq_msg_t req;
        zmq_msg_init_size(&req, strlen("HELLO"));
        memcpy(zmq_msg_data(&req), "HELLO", 5);
        printf("Sending: HELLO - %d \n", count);
        zmq_msg_send(&req, request, 0);
        zmq_msg_close(&req);

        // sleep(2);
        zmq_msg_t reply;
        zmq_msg_init(&reply);
        zmq_msg_recv(&reply, request, 0);
        printf("Received: %d\n", count);
        zmq_msg_close(&reply);
        count++;
    }

    zmq_close(request);
    zmq_ctx_destroy(context);

    return 0;
}
