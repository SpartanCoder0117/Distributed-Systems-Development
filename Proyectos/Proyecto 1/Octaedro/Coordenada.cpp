#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz){}

double Coordenada::getX(){
    return x;
}

double Coordenada::getY(){
    return y;
}

double Coordenada::getZ(){
    return z;
}

Coordenada Rectangulo::getPrimer(){
    return primerC;
}

Coordenada Rectangulo::getSegunda(){
    return segundaC;
}

Coordenada Rectangulo::getTercera(){
    return tercerC;
}

Coordenada Rectangulo::getCuarta(){
    return cuartaC;
}