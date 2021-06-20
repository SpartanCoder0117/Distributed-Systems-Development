#include "SocketMulticast.h"
#include <iostream>

using namespace std;

SocketMulticast::SocketMulticast(int puerto){
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(s<0){
        cout << "Error al crear el socket" << endl;
    }
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto); // si es 0, el puerto será asignado por el Sistema Operativo
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));     

}

SocketMulticast::~SocketMulticast(){
    close(s);
}

int SocketMulticast::recibe(PaqueteDatagrama & p){
    int recibidos = 0;
    char datos[p.obtieneLongitud()];
    socklen_t clilen = sizeof(direccionForanea);
    recibidos = recvfrom(s, datos, p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    p.inicializaDatos(datos);

    /* Inprimimos lo que recibimos */
	printf("\nSe recibieron %d bytes desde %s: \n", recibidos, p.obtieneDireccion());
	printf("Mensaje: %s\n", datos);

    return recibidos;
}

int SocketMulticast::envia(PaqueteDatagrama & p, unsigned char ttl){
    int enviados = 0;       

    TTL = ttl;
    
    if(setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL))<0)
        cout << "Error de transmicion " << endl;

    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());  

    enviados = sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));

    if (enviados == -1)
        cout << "No se envio nada :(" << endl;
    else
        cout << "Enviando..." << endl; 
    
    return enviados;
}

void SocketMulticast::unirseGrupo(char *IP){
    //struct ip_mreq mreq;

    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);  

    if(setsockopt (s, IPPROTO_IP, IP_ADD_MEMBERSHIP, ( void *) & multicast, sizeof (multicast))<0){
        cout << "Error al unirse al grupo" << endl;
    }  
    else   
        cout << "Ya me uni al grupo " << IP << endl;

}

void SocketMulticast::salirseGrupo(char *IP){
    //struct ip_mreq mreq;
    if(setsockopt (s, IPPROTO_IP, IP_DROP_MEMBERSHIP, ( void *) & multicast, sizeof (multicast))<0){
        cout << "Error al salirse del grupo" << endl;
    }  
    else
        cout << "Ya me sali del grupo " << IP << endl;
}


int SocketMulticast::obtieneID(){
    return s;
}

void SocketMulticast::inicializaID(int ID){
    s = ID;
}

