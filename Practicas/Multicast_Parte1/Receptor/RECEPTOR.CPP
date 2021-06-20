#include "SocketMulticast.h"
#include "Mensaje.h"
#include <iostream>

/*parámetros la IP de multicast y el puerto en el
que escucha.*/
using namespace std;
int main(int argc, char* argv[]){
    if(argc!= 3){
        cout << "Error: MODO de uso <IP> <Puerto> " << endl;
        exit(1);
    }

    char* IP = argv[1];
    int puerto = atoi(argv[2]);

    PaqueteDatagrama p = PaqueteDatagrama(65000);
    
    SocketMulticast sm = SocketMulticast(puerto);
    sm.unirseGrupo(IP);
    
    //for(;;){
        cout << "\nEsperando..." << endl;
        sm.recibe(p);
    //}
    sm.salirseGrupo(IP);
   
}