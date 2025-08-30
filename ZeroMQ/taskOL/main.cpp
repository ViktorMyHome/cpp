#include <string.h>
#include "zmq.h"
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <atomic>
#include <thread>
#include <mutex>
using namespace std;

#define QUANTITY_OF_CLIENTS 3

std::atomic<int> g_count = 0;
mutex mtx;
mutex mtx_sr;
void *srv;
struct data_to_server_thread{
    uint32_t X_;
    uint32_t routing_id_;
};
data_to_server_thread dts[QUANTITY_OF_CLIENTS];



// steps to follow during zmq lib installation
// download zmq library from git:
// https://github.com/zeromq/libzmq/
// ./autogen.sh
// ./configure --enable-drafts=yes
// make
// sudo make install

// to compile the code:
// make clean
// make all

// to lunch the demo:
// ./main

// X is created based on client thread number
// thread #0 -> 10
// thread #1 -> 20
// thread #2 -> 30



double generate_value(uint32_t X)
{
    srand(time(NULL));

    double normalizedRand = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

    return (normalizedRand * static_cast<double>(2*X) - static_cast<double>(X));
}

void client()
{
    void *ctx = zmq_ctx_new();
    assert(ctx);
    void *client = zmq_socket(ctx, ZMQ_CLIENT);
    assert(client);
    int rc = zmq_connect(client, "tcp://127.0.0.1:8080");
    assert(rc == 0);

    int client_count;
    {
        lock_guard<mutex> lock(mtx);
        client_count = g_count;
        printf(" client %d: is started\n", client_count);
        g_count++;
    }

    zmq_msg_t msg;
    sleep(2);
    zmq_msg_init_size(&msg, 4);
    char *data = static_cast<char *>(zmq_msg_data(&msg));
    data[0] = 'R';
    data[1] = 'E';
    data[2] = 'Q';
    data[3] = 48 + client_count;
        // send request
    rc = zmq_msg_send(&msg, client, 0);
    assert(4 == rc);
    printf("   client %d: request is sent\n", client_count);

    while(1)
    {
        zmq_msg_t msg_double;
        rc = zmq_msg_init_size(&msg_double, sizeof(double));
        assert (rc == 0);
        rc = zmq_msg_recv (&msg_double, client, 0);
        assert (rc != -1);
        double *ddata = static_cast<double*>(zmq_msg_data(&msg_double));
        printf("   client %d: received %d bytes value = %f\n", client_count, rc, *ddata);
        zmq_msg_close (&msg_double);
    }

    zmq_msg_close(&msg);
    zmq_close(client);
}

void server_thread(data_to_server_thread* pData)
{

    for(int i=0; i<10; i++)
    {
        // Send the reply to client
        sleep(1);
        lock_guard<mutex> lock(mtx_sr);
        zmq_msg_t reply_msg;
        int rc = zmq_msg_init_size(&reply_msg, sizeof(double)); assert(rc == 0);
        zmq_msg_set_routing_id(&reply_msg, pData->routing_id_);
        // create X based on client thread number
        // thread #0 -> 10
        // thread #1 -> 20
        // thread #2 -> 30
        double value = generate_value(((pData->X_)-48+1)*10);
        uint8_t* idata = (uint8_t*)zmq_msg_data(&reply_msg);
	    memcpy(idata, &value, sizeof(double));
        printf(" server: sent value = %f to routing_id = %d\n", value, pData->routing_id_);
        zmq_msg_send(&reply_msg, srv, 0);
        zmq_msg_close (&reply_msg);
    }
}

void server(void)
{
    printf(" server: is started\n");
        //Receiving a client message and routing ID
    void *ctx = zmq_ctx_new ();
    assert (ctx);

    srv = zmq_socket (ctx, ZMQ_SERVER);
    assert (srv);
    int rc = zmq_bind (srv, "tcp://127.0.0.1:8080");
    assert (rc == 0);

    while(1)
    {
        zmq_msg_t message;
        rc = zmq_msg_init (&message);
        assert (rc == 0);
        //  Receive a request from client
        rc = zmq_msg_recv (&message, srv, 0);
        assert (rc != -1);
        uint32_t routing_id = zmq_msg_routing_id (&message);
        assert (routing_id);
        char *cdata = static_cast<char *>(zmq_msg_data(&message));
        cdata[4]='\0';
        dts[static_cast<uint32_t>(cdata[3])].routing_id_ = routing_id;
        dts[static_cast<uint32_t>(cdata[3])].X_ = static_cast<uint32_t>(cdata[3]);
        printf(" server: received %d bytes = %s from routing id = %d X=%d\n", rc, cdata, routing_id, dts[static_cast<uint32_t>(cdata[3])].X_);
        zmq_msg_close (&message);

        std::thread thread_srever_unit(server_thread, &dts[static_cast<uint32_t>(cdata[3])]);
        thread_srever_unit.detach();
    }

    zmq_close(srv);
}



int main() {

    thread thread_s(server);
    thread thread_c1(client);
    thread thread_c2(client);
    thread thread_c3(client);
    thread_s.detach();
    thread_c1.detach();
    thread_c2.detach();
    thread_c3.detach();

    sleep(30);

    return 0;
}
