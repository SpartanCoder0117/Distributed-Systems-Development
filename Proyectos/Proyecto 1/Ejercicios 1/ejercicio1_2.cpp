#include <iostream>
using namespace std;

#define G 9.81

double altura(double t);

int main(){
    double tiempo;
    cout << "Ingrese los segundos: ";
    cin >> tiempo;
    cout << "La altura es: " << altura(tiempo) << " metros" << endl;
    return 0;
}

double altura(double t){
    double v = 0;
    double alt = (v * t) + (G * (t * t)) / 2;
    return alt;
}