#include "Fraccion.h"
#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    double *res;
    Fraccion f;

    cout << "Ingresa el numerador: ";
    cin >> a;
    cout << "Ingresa el denominador: ";
    cin >> b;

    f.setNum(a);
    f.setDen(b);

    cout << "El resultado de la division es: " << f.Div(f.getNum(), f.getDen()) << endl;
    
    res = f.minima(f.getNum(), f.getDen());
    cout << "Su minima expresion es: " << res[0] << " / " << res[1] << endl;

}