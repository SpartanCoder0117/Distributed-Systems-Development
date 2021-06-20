#ifndef SOCKET_MULTICAST_H_
#define SOCKET_MULTICAST_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <sys/time.h>
#include "PaqueteDatagrama.h"
using namespace std;

class SocketMulticast{
    private:
        int s; 
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        unsigned char TTL;  
        struct ip_mreq multicast;
    public:
        SocketMulticast(int);
        ~SocketMulticast();
        int recibe(PaqueteDatagrama & p);
        int envia(PaqueteDatagrama & p, unsigned char ttl);
        //Se une a un grupo multicast, recibe la IP multicast
        void unirseGrupo(char *);
        //Se sale de un grupo multicast, recibe la IP multicast
        void salirseGrupo(char *);
        //Get  and  Set
        void inicializaID(int);
        int obtieneID();



};

#endif