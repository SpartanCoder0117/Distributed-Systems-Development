#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
#include "Rectangulo.h"
#include "Coordenada.h"

class Ortoedro
{
    private:
        Rectangulo r1;
        Rectangulo r2;
        Rectangulo r3;
        Rectangulo r4;
        Rectangulo r5;
        Rectangulo r6;
    public:
        Ortoedro(Rectangulo, Rectangulo, Rectangulo, Rectangulo, Rectangulo, Rectangulo);
        Rectangulo getVer1();
        Rectangulo getVer2();
        Rectangulo getVer3();
        Rectangulo getVer4();
        Rectangulo getVer5();
        Rectangulo getVer6();
        double getArea(double, double, double);
        double getVolumen(double, double, double);
};
#endif
