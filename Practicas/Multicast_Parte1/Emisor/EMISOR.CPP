#include "SocketMulticast.h"
#include "Mensaje.h"
#include <iostream>

#include <netdb.h>
#include <cstdlib>
#include <cstring>

using namespace std;

/* la IP de multicast, el puerto, el valor de TTL y una cadena
encerrada entre comillas.*/

int main(int argc, char* argv[]){
    if(argc!= 5){
        cout << "Error: MODO de uso <IP> <Puerto> <TTL> <Cadena entre comillas>" << endl;
        exit(1);
    }
    
    char* IP = argv[1];
    int puerto = atoi(argv[2]);
    int TTL = atoi(argv[3]);
    char* Cadena = argv[4];

    struct mensaje *msj = (struct mensaje *)malloc(sizeof(struct mensaje));
    msj->messageType =1;
    msj->operationId =0;
    msj->requestId =0;
    msj->puerto = puerto;
    memcpy(msj->IP, IP, strlen(IP));
    memcpy(msj->arguments, Cadena, strlen(Cadena));

    // PaqueteDatagrama p(sizeof(mensaje));
    // p.inicializaIp(msj->IP);
    // p.inicializaPuerto(msj->puerto);
    // p.inicializaDatos(msj->arguments);

    SocketMulticast sm = SocketMulticast(puerto);
    
    PaqueteDatagrama p(msj->arguments, sizeof(mensaje), msj->IP, msj->puerto);
    
   
    //while (true){
        sm.envia(p,TTL);   
        //sleep(3);
    //}
   
    

}
