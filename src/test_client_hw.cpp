//  Hello World client
#include <zmq.hpp>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    // Conection to the Server
    printf ("Connecting to hello world server…\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://*:6666");
    
    // Sending Data to the Server 
    // 10 times "Hello" and wait reply from the server "World"
    int request_nbr; // Var for count 10 times
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        char buffer [10];
        printf ("Sending Hello %d…\n", request_nbr);
        zmq_send (requester, "Hello", 5, 0);
        zmq_recv (requester, buffer, 10, 0);
        printf ("Received World %d\n", request_nbr);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
