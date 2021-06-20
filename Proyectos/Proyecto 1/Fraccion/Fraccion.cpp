#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion(){}

void Fraccion::setNum(int numerador){
    num = numerador;
}

void Fraccion::setDen(int denominador){
    deno = denominador;
}

int Fraccion::getDen(){
    return deno;
}

int Fraccion::getNum(){
    return num;
}

double *Fraccion::minima(int nume, int deno){
    double *res = new double[2];
    double aux;

    aux = (nume >= deno) ? deno : num;

    for(int i = 2; i <= aux; i++){
        if(num % i == 0 && deno % i == 0){
            num /= i;
            deno /= i;
        }
    }
    res[0] = num;
    res[1] = deno;
    return res;
}

double Fraccion::Div(int nume, int deno){
    return (double)num / (double)deno;
}