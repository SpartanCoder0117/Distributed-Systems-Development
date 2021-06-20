#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main(){
    double x, y, z, area, volumen;

    Rectangulo r1(Coordenada(0, 0, 0), Coordenada(5, 10, 0), Coordenada(5, 0, 0), Coordenada(0, 10, 0));
    Rectangulo r2(Coordenada(0, 10, 7), Coordenada(0, 10, 0), Coordenada(5, 10, 0), Coordenada(5, 10, 7));
    Rectangulo r3(Coordenada(0, 10, 7), Coordenada(5, 10, 7), Coordenada(0, 0, 7), Coordenada(5, 0, 7));
    Rectangulo r4(Coordenada(0, 0, 0), Coordenada(5, 0, 0), Coordenada(0, 0, 7), Coordenada(5, 0, 7));
    Rectangulo r5(Coordenada(0, 0, 0), Coordenada(0, 0, 7), Coordenada(0, 10, 7), Coordenada(0, 10, 0));
    Rectangulo r6(Coordenada(5, 0, 0), Coordenada(5, 0, 7), Coordenada(5, 10, 0), Coordenada(5, 10, 7));

    Ortoedro ort(r1, r2, r3, r4, r5, r6);

    x = r4.distancia(ort.getVer4().getTercera(), ort.getVer4().getCuarta());
    y = r4.distancia(ort.getVer4().getSegunda(), ort.getVer4().getCuarta());
    z = r4.distancia(ort.getVer4().getCuarta(), ort.getVer3().getSegunda());

    area = ort.getArea(x, y, z);
    volumen = ort.getVolumen(x, y, z);

    cout << "El area es: " << area << endl;
    cout << "El volumen es: " << volumen <<endl;

    return 0;
}