#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

Ortoedro::Ortoedro(Rectangulo rr1, Rectangulo rr2, Rectangulo rr3, Rectangulo rr4, Rectangulo rr5, Rectangulo rr6) : r1(rr1.getPrimer(), rr1.getSegunda(), rr1.getTercera(), rr1.getCuarta()), r2(rr2.getPrimer(), rr2.getSegunda(), rr2.getTercera(), rr2.getCuarta()), r3(rr3.getPrimer(), rr3.getSegunda(), rr3.getTercera(), rr3.getCuarta()), r4(rr4.getPrimer(), rr4.getSegunda(), rr4.getTercera(), rr4.getCuarta()), r5(rr5.getPrimer(), rr5.getSegunda(), rr5.getTercera(), rr5.getCuarta()), r6(rr6.getPrimer(), rr6.getSegunda(), rr6.getTercera(), rr6.getCuarta()){}

double Ortoedro::getArea(double x, double y, double z){
    return (2 * x * y) + (2 * x * z) + (2 * y * z);
}

double Ortoedro::getVolumen(double x, double y, double z){
    return x * y *z;
}

Rectangulo Ortoedro::getVer1(){
    return r1;
}

Rectangulo Ortoedro::getVer2(){
    return r2;
}

Rectangulo Ortoedro::getVer3(){
    return r3;
}

Rectangulo Ortoedro::getVer4(){
    return r4;
}

Rectangulo Ortoedro::getVer5(){
    return r5;
}

Rectangulo Ortoedro::getVer6(){
    return r6;
}
