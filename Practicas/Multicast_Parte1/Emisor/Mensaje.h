#ifndef _MENSAJE_
#define _MENSAJE_

#define TAM_MAX_DATA 65000

struct mensaje{
    int messageType;
    unsigned int requestId;
    char IP[16];
    int puerto;
    int operationId;
    char arguments[TAM_MAX_DATA];
};
#endif