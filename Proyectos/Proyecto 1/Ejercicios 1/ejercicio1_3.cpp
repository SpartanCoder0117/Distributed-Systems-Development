#include <iostream>
using namespace std;

double segundos(double s);
double minutos(double m);
double horas(double h);

int main(){
    double seg;
    int h, m, s;

    cout << "Ingresa los segundos: ";
    cin >> seg;

    h = (int)horas(seg);
    m = (int)minutos(horas(seg));
    s = (int)segundos(minutos(horas(seg)));

    cout << "Su equivalencia es: " << h << " Horas " << m << " Minutos " << s << " Segundos" << endl;

    return 0;
}

double segundos(double s){
    s = s - (int)s;
    return s * 60;
}

double minutos(double m){
    m = m - (int)m;
    return m * 60;
}

double horas(double h){
    return h / 3600;
}
