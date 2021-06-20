#include <iostream>
#include "Temperatura.h"
using namespace std;

int main(){
    double kelvin;
    Temperatura t;

    cout << "Ingresa los grados kelvin: ";
    cin >> kelvin;

    t.setC(kelvin);
    t.setF(kelvin);
    t.setK(kelvin);

    cout << "Conversion a celsius: " << t.K_C(t.getC()) << " °C" << endl;
    cout << "Conversion a fahrenheit: " << t.K_F(t.getF()) << " °F" << endl;
    cout << "Kelvin: " << t.getK() << " °K" << endl;

    return 0;
}