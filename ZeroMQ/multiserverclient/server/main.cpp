#include <iostream>
#include <string.h>
#include <unistd.h>
#include "zmq.h"
#include <assert.h>
using namespace std;


//
// ROUTER uses the message envelope to decide which client to route a reply back to
// ROUTER will route messages asynchronously to any peer
// connected to it, if you provide the correct routing address via a properly constructed envelope
// All we need to know is the address of the peer we want to talk to, and then we
// can then send it messages asynchronously, via a ROUTER
// The ROUTER is the one and only ØMQ
// socket type capable of being told "send this message to X" where X is the address of a connected peer
// By default, a peer has a null identity and the ROUTER will generate a UUID and use that to refer to
// the connection when it delivers you each incoming message from that peer
// If the peer socket set an identity, the ROUTER will give that identity when it delivers an incoming
// request envelope from that peer.

// There are at least three routing patterns, one for each of the socket types we can easily connect to a ROUTER:
// •ROUTER-to-DEALER.
// •ROUTER-to-REQ.->my case  3.4
// •ROUTER-to-REP.

// https://github.com/zeromq/libzmq/blob/master/doc/zmq_recv.adoc


//ZMQ_REQ
//           A socket of type ZMQ_REQ is used by a client to send requests to and receive replies from a service.
//           This socket type allows only an alternating sequence of zmq_send(request) and subsequent
//           zmq_recv(reply) calls. Each request sent is round-robined among all services, and each reply received
//           is matched with the last issued request.

//ZMQ_REP
//           A socket of type ZMQ_REP is used by a service to receive requests from and send replies to a client.
//           This socket type allows only an alternating sequence of zmq_recv(request) and subsequent
//           zmq_send(reply) calls. Each request received is fair-queued from among all clients, and each reply
//           sent is routed to the client that issued the last request. If the original requester does not exist
//           any more the reply is silently discarded.

//ZMQ_ROUTER
//           A socket of type ZMQ_ROUTER is an advanced socket type used for extending request/reply sockets. When
//           receiving messages a ZMQ_ROUTER socket shall prepend a message part containing the routing id of the
//           originating peer to the message before passing it to the application. Messages received are
//           fair-queued from among all connected peers. When sending messages a ZMQ_ROUTER socket shall remove
//           the first part of the message and use it to determine the _routing id _ of the peer the message shall
//           be routed to.

//        When a ZMQ_REQ socket is connected to a ZMQ_ROUTER socket, in addition to the routing id of the
//           originating peer each message received shall contain an empty delimiter message part. Hence, the
//           entire structure of each received message as seen by the application becomes: one or more routing id
//           parts, delimiter part, one or more body parts. When sending replies to a ZMQ_REQ socket the
//           application must include the delimiter part.

// Following are the thread safe sockets: * ZMQ_CLIENT * ZMQ_SERVER * ZMQ_DISH * ZMQ_RADIO * ZMQ_SCATTER *ZMQ_GATHER * ZMQ_PEER * ZMQ_CHANNEL

int main() {

    void* context = zmq_ctx_new();
    void* server = zmq_socket(context, ZMQ_ROUTER);// create new context


    int rc = zmq_bind(server, "tcp://*:5555");
    assert(rc == 0);
    printf("server starting...\n");

    for(;;){

//        char buffer[20] = {'\0'};
//        char identity[2] = {'\0'};
//        zmq_recv(respond, identity, 2, ZMQ_SNDMORE);
//        zmq_recv(respond, buffer, 20, 0);
//        printf("identity %s server received %s\n",identity, buffer);
//        sleep(1);
//        zmq_send(respond, "A", 1, ZMQ_SNDMORE);
//        zmq_send(respond, "send from server", 16, 0);
        
        
        zmq_msg_t message_get;
        rc = zmq_msg_init (&message_get);
        assert (rc == 0);
        //  Receive a message from socket
        rc = zmq_msg_recv (&message_get, server, 0);
        assert (rc != -1);
        uint32_t routing_id = zmq_msg_routing_id (&message_get);
        assert (routing_id);
        printf(" routing_id = %d\n",routing_id); 
        
        
        
        zmq_msg_t msg_send;
        int rc = zmq_msg_init_size (&msg_send, 6);
        assert (rc == 0);
        /* Fill in message content with 'AAAAAA' */
        memset (zmq_msg_data (&msg_send), 'A', 6);
        
        rc = zmq_msg_set_routing_id(&msg_send, routing_id);
        assert(rc==0);
        
        rc = zmq_msg_send (&msg_send, server, 0);
        assert(rc==0);
        
        
        
        // zmq_msg_t request;
        // zmq_msg_init(&request);
        // zmq_msg_recv(&request, respond, 0);
        // printf("Server received: \n");
        // zmq_msg_close(&request);
        // sleep(1);// sleep 1 second
        // zmq_msg_t reply;
        // zmq_msg_init_size(&reply, strlen("world"));
        // memcpy(zmq_msg_data(&reply), "world", 5);
        // zmq_msg_send(&reply, respond, 0);
        // zmq_msg_close(&reply);
    }

    zmq_close(server);
    zmq_ctx_destroy(context);

    return 0;
}
