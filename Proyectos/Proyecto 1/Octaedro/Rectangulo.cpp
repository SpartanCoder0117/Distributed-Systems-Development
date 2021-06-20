#include "Rectangulo.h"
#include <iostream>
#include <math.h>
using namespace std;

Rectangulo::Rectangulo(Coordenada c1, Coordenada c2, Coordenada c3, Coordenada c4) : primerC(c1.getX(), c1.getY(), c1.getZ()), segundaC(c2.getX(), c2.getY(), c2.getZ()), tercerC(c3.getX(), c3.getY(), c3.getZ()), cuartaC(c4.getX(), c4.getY(), c4.getZ()){}
Rectangulo::Rectangulo(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) : primerC(x1, y1, z1), segundaC(x2, y2, z2), tercerC(x3, y3, z3), cuartaC(x4, y4, z4){}

double Rectangulo::getArea(double alto, double ancho){
    return alto * ancho;
}

double Rectangulo::distancia(Coordenada c2, Coordenada c1){
    return sqrt(((c2.getX() - c1.getX()) * (c2.getX() - c1.getX())) + (c2.getY() - c1.getY()) * (c2.getY() - c1.getY()) + (c2.getZ() - c1.getZ()) * (c2.getZ() - c1.getZ()));
}

void Rectangulo::imprime(){
    cout << "Primera coordenada: X = " << primerC.getX() << " Y = " << primerC.getY() << " Z = " << primerC.getZ() << endl;
    cout << "Segunda coordenada: X = " << segundaC.getX() << " Y = " << segundaC.getY() << " Z = " << segundaC.getZ() << endl;
    cout << "Tercer coordeanada: X = " << tercerC.getX() << " Y = " << tercerC.getY() << " Z = " << tercerC.getZ() << endl;
    cout << "Cuarta coordenada: X = " << cuartaC.getX() << " Y = " << cuartaC.getY() << " Z =" << cuartaC.getZ() << endl;
}