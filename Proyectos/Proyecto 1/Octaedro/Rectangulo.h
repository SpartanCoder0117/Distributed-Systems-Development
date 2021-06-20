#ifndef RECTAN_H_
#define RECTAN_H_
#include "Coordenada.h"

class Rectangulo
{
    private:
        Coordenada primerC;
        Coordenada segundaC;
        Coordenada tercerC;
        Coordenada cuartaC;
    public:
    Rectangulo(Coordenada, Coordenada, Coordenada, Coordenada);
    Rectangulo(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4);
    void imprime();
    double distancia(Coordenada, Coordenada);
    double getArea(double, double);
    Coordenada getPrimer();
    Coordenada getSegunda();
    Coordenada getTercera();
    Coordenada getCuarta();
};
#endif
