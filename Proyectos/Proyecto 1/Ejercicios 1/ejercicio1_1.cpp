#include <iostream>
using namespace std;

double babilonico(double a);

int main(){
    double numero;
    cout << "Ingrese un número: ";
    cin >> numero;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout << "La raiz es: " << babilonico(numero) << endl;

    return 0;
}

double babilonico(double a){
    double b = a;
    double c = 0;
    while (c != b){
        c = b;
        b = (a / b + b) / 2;
    }
    return b;
}