#include "Gusano.h"
#include <iostream>

using namespace std;

Gusano::Gusano(){ }

int Gusano::getX(){ return X; }
int Gusano::getY(){ return Y; }
int Gusano::getMovimiento(){ return movimiento_a_realizar; }
int Gusano::getRadio(){ return radio; }
void Gusano:: setX(int x){ X = x;}
void Gusano:: setY(int y){ Y = y;}
void Gusano:: setMovimiento(int movimiento){ movimiento_a_realizar = movimiento;}
void Gusano:: setRadio(int Radio){ radio = Radio;}
