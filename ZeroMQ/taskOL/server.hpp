#include "data.hpp"
using namespace std;

#define MAX_QUANTITY_OF_CLIENTS 100

mutex mtx_sr;
data_to_server_thread g_dts[MAX_QUANTITY_OF_CLIENTS];
int thr = 0;
void * srv;


class server{

    std::thread * thread_server_unit[100];

    int port;
    const char* protocol_address = "tcp://127.0.0.1:";
    string protocol_address_port;
    void *ctx;

    data_to_server_thread dts;

    static double generate_value(double X)
    {
        srand(time(NULL));
        double normalizedRand = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        return (normalizedRand * 2.0 * X - static_cast<double>(X));
    }

    static void server_thread()
    {
        int j = thr;
        for(int i=0; i<QUANTITY_OF_ELEMENTS; i++)
        {
            // Send the reply to client
            sleep(1);
            {
            lock_guard<mutex> lock(mtx_sr);
            zmq_msg_t reply_msg;
            int rc = zmq_msg_init_size(&reply_msg, sizeof(double)); assert(rc == 0);
            zmq_msg_set_routing_id(&reply_msg, g_dts[j].routing_id_);
            double value = generate_value(g_dts[j].X_);
            uint8_t* idata = (uint8_t*)zmq_msg_data(&reply_msg);
	        memcpy(idata, &value, sizeof(double));
            printf(" server: sent value = %f to client %d routing_id = %d\n", value, j, g_dts[j].routing_id_);
            zmq_msg_send(&reply_msg, srv, 0);
            zmq_msg_close (&reply_msg);
            }
        }
    }

public:

    ~server()
    {
        zmq_close(srv);
    }

    server()
    {
        std::ifstream configFile("server_config.txt");
        if (!configFile.is_open()) {
            std::cerr << "Error opening server config file!" << std::endl;
        } else {
            std::string line;
            std::getline(configFile, line);
            port = std::stoi(line);
            std::string temp(protocol_address);
            protocol_address_port = temp + line;
            std::cout<<" client protocol_address_port = "<<protocol_address_port<<std::endl;
            
            ctx = zmq_ctx_new ();
            assert (ctx);

            srv = zmq_socket (ctx, ZMQ_SERVER);
            assert (srv);
            int rc = zmq_bind(srv, protocol_address_port.c_str());
            assert (rc == 0);
            configFile.close();
        }
    }


    server(server const&) = delete;
    void operator=(server const&) = delete;

    void start()
    {
        printf(" server: is started\n");

        for(int i = 0; i < MAX_QUANTITY_OF_CLIENTS; i++)
        {
            zmq_msg_t message;
            int rc = zmq_msg_init (&message);
            assert (rc == 0);
            //  Receive a request from client
            rc = zmq_msg_recv (&message, srv, 0);
            assert (rc != -1);
            uint32_t routing_id = zmq_msg_routing_id (&message);
            assert (routing_id);
            double *ddata = static_cast<double *>(zmq_msg_data(&message));
            g_dts[i].routing_id_ = routing_id;
            g_dts[i].X_ = static_cast<double>(*ddata);
            printf(" server: received %d bytes = %f from routing id = %d X=%f\n", rc, *ddata, g_dts[i].routing_id_, g_dts[i].X_);
            zmq_msg_close (&message);
            thr = i;
            std::thread thread_srever_unit(server_thread);
            thread_srever_unit.detach();
        }
    }

};
