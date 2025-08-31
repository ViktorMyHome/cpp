#include "data.hpp"
#include <set>
using namespace std;

mutex mtx_cl;
std::atomic<int> g_count;

class client
{
    int port;
    const char* protocol = "tcp://";
    string protocol_address_port;
    string address;
    double value;
    ifstream configFile;
    ofstream outFile;
    void *cl;
    void *ctx;
    data_to_server_thread dts;
    std::set<double> client_set;

public:

    client()
    {
        configFile.open("client_config.txt", std::ios_base::in);
        if (!configFile.is_open()) {
            std::cerr << "Error opening client config file!" << std::endl;
        } else {
            std::string line;
            for(int i=0; std::getline(configFile, line); i++){
                switch(i){
                    case(0):
                        port = std::stoi(line);
                        break;
                    case(1):
                        address = line;
                        break;
                    case(2):
                        value = stod(line);
                        break;
                }
            }
            protocol_address_port = protocol + address + ":" + to_string(port);
            std::cout<<" client protocol_address_port = "<<protocol_address_port<<std::endl;
        }
        configFile.close();
        ctx = zmq_ctx_new();
        assert(ctx);
        cl = zmq_socket(ctx, ZMQ_CLIENT);
        assert(cl);
        int rc = zmq_connect(cl, protocol_address_port.c_str());
        assert(rc == 0);
    }

    ~client()
    {
        zmq_close(cl);
    }

    void start()
    {

        int client_count;
        {
            lock_guard<mutex> lock(mtx_cl);
            client_count = g_count.load();
            printf(" client %d: is started\n", client_count);
            g_count++;
        }

        zmq_msg_t msg;
        sleep(2);
        zmq_msg_init_size(&msg, 8);
        double *data = static_cast<double *>(zmq_msg_data(&msg));
        *data = value;
        int rc = zmq_msg_send(&msg, cl, 0);
        assert(8 == rc);
        printf("   client %d: request is sent\n", client_count);
        zmq_msg_close(&msg);

        for(int i=0; i<QUANTITY_OF_ELEMENTS; i++)
        {
            zmq_msg_t msg_double;
            rc = zmq_msg_init_size(&msg_double, sizeof(double));
            assert (rc == 0);
            rc = zmq_msg_recv (&msg_double, cl, 0);
            assert (rc != -1);
            double *ddata = static_cast<double*>(zmq_msg_data(&msg_double));
            printf("   client %d: received %d bytes value = %f\n", client_count, rc, *ddata);
            client_set.insert(*ddata);
            zmq_msg_close (&msg_double);
        }
        outFile.open("out_file.txt", std::ios_base::out);
        for(auto element:client_set)
        {
            outFile<<element<<std::endl;
        }
        outFile.close();
    }
};
