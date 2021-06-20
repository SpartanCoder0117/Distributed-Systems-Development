#include "Temperatura.h"
#include <iostream>
using namespace std;

Temperatura::Temperatura(){}

void Temperatura::setK(int k){
    kelvin = k;
}

void Temperatura::setF(int f){
    fahrenheit = f;
}

void Temperatura::setC(int c){
    celsius = c;
}

int Temperatura::getK(){
    return kelvin;
}

int Temperatura::getF(){
    return fahrenheit;
}

int Temperatura::getC(){
    return celsius;
}

double Temperatura::K_C(int kc){
    return kc - 273.15;
}

double Temperatura::K_F(int kf){
    return ((kf - 273.15) * 1.8) + 32;
}