#include "gfx.h"
#include "Gusano.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<Gusano> gusano;

double *Llenar_Auxiliares(){
	double *aux = new double[27];	
	double decimales;	
	decimales = 0;
	for(int i = 0; i < 13; i++){
		aux[i] = decimales;
		decimales += 0.01;		
	}
	decimales = 300;
	for(int i = 13; i < 26; i++){
		aux[i] = decimales;
		decimales -= 0.01;		
	}
	return aux; 	
}

void Movimiento(int x, int y, int indice){
	gfx_point(gusano[indice].getX(), gusano[indice].getY());			
	gusano[indice].setY(y);
	gusano[indice].setX(x);	
	return;
}

void funcion_Movimientos(int tamano_gusano){
	int ayuda = gusano[0].getMovimiento();
	double *aux_circulo = new double[33];
	aux_circulo = Llenar_Auxiliares();
	double *posX = new double[40];
	double *posY = new double[40];		
	double auxX = 0, auxY = 0;
	int cola = 3;
	double auxiliar = 0;
	//Realización de movimientos
	for(int j = 0; j < 20; j ++){
		//Obtención de cada posición del gusano
		for(int k = 0; k < tamano_gusano; k++){
			posX[k] = gusano[k].getX();
			posY[k] = gusano[k].getY();
		}		
		//50 pixeles por cada movimiento			
		for(int i = 0; i < 50; i++){
			gfx_clear();
			gfx_color(0,200,100);
			//Pintar cada punto del gusano
			auxiliar=0;
			for(int l = 0; l < tamano_gusano; l++){
				if(gusano[l].getMovimiento() == 0){		//Movimiento Derecha
					for(double h = 0; h < 3; h+=0.1)				
						Movimiento(i + posX[l] - h, posY[l], l);
				}
				if(gusano[l].getMovimiento() == 1){ 	//Movimiento Izquierda
					for(double h = 0; h < 3; h+=0.1)				
						Movimiento(posX[l] - i + h, posY[l], l); 
				}
				if(gusano[l].getMovimiento() == 2){		//Movimiento Arriba
					for(double h = 0; h < 3; h+=0.1)					
						Movimiento(posX[l], posY[l] - i + h, l); 
				}
				if(gusano[l].getMovimiento() == 3){ 	//Movimiento Abajo
					for(double h = 0; h < 3; h+=0.1)				
						Movimiento(posX[l], posY[l] + i - h, l); 
				}
				if(gusano[l].getMovimiento() == 4){ 	//Movimiento Diagonal Superior Derecha
					for(double h = 0; h < 3; h+=0.1)					
						Movimiento(i + posX[l] - h, posY[l] - i + h, l); 
				}
				if(gusano[l].getMovimiento() == 5){		//Movimiento Diagonal Superior Izquierda
					for(double h = 0; h < 3; h+=0.1)					
						Movimiento(posX[l] - i + h, posY[l] - i + h, l); 
				}
				if(gusano[l].getMovimiento() == 6){ 	//Movimiento Diagonal Inferior Derecha
					for(double h = 0; h < 3; h+=0.1)					
						Movimiento(i + posX[l] - h, posY[l] + i - h, l); 
				}
				if(gusano[l].getMovimiento() == 7){		//Movimiento Diagonal Inferior Izquierda
					for(double h = 0; h < 3; h+=0.1)					
						Movimiento(posX[l] - i + h, posY[l] + i - h, l); 
				}
				if(gusano[l].getMovimiento() == 8){		//Movimiento Serpenteante Derecha
					for(double h = 0; h < 1; h += 0.021875){					
						if(posX[l] + i + i/h < posX[l] + 30){
							Movimiento(posX[l] + i + i/h, 4*cos(i/h)+posY[l],l);
						}
					}
					if(i >=15)		
						gusano[l].setMovimiento(0);
					
				}
				if(gusano[l].getMovimiento() == 9){		//Movimiento Serpenteante Izquierda
					/*for(double h = 0; h < cola; h+=0.1)					
						Movimiento(posX[l] - i + h, 5 * cos(i) + posY[l], l);*/
										
					for(double h = 0; h < 1; h += 0.021875){					
						if(posX[l] + i + i/h < posX[l] + 30){
							Movimiento(posX[l] - i - i/auxiliar, 4*cos(i/auxiliar)+posY[l],l);
						}
					}
					if(i >=15){		
						gusano[l].setMovimiento(1);		
					}
					auxiliar++;
				}
				if(gusano[l].getMovimiento() == 10){	//Movimiento Serpenteante Arriba
					/*for(double h = 0; h < cola; h+=0.1)					
						Movimiento(5 * cos(i) + posX[l], posY[l] - i + h, l);*/
					for(double h = 0; h < 1; h += 0.021875){					
						if(posX[l] + i + i/h < posX[l] + 30){
							Movimiento(4*cos(i/h)+posX[l],  posY[l] - i - i/h,l);
						}
					}
					if(i >=15){		
						gusano[l].setMovimiento(2);		
					}
				}
				if(gusano[l].getMovimiento() == 11){ 	//Movimiento Serpenteante Abajo	
					/*for(double h = 0; h < cola; h+=0.1)					
						Movimiento(5 * cos(i) + posX[l], posY[l] + i - h, l);
					*/for(double h = 0; h < 1; h += 0.021875){					
						if(posY[l] + i + i/h < posY[l] + 30){
							Movimiento(4*cos(i/h)+posX[l],  posY[l] + i + i/h,l);
						}
					}
					if(i >=15){		
						gusano[l].setMovimiento(3);		
					}
				}
				if(gusano[l].getMovimiento() == 12){	//Movimiento Circular Derecha
					for(int h = 0; h < 13; h++){
	        Movimiento(gusano[l].getRadio()*cos(aux_circulo[h])+posX[l],gusano[l].getRadio()*sin(aux_circulo[h])+posY[l],l);
						aux_circulo[h] += 0.01;
					}			        
				}
				if(gusano[l].getMovimiento() == 13){	//Movimiento Circular Izquierda
		                 		for(int h = 13; h < 26; h++){
	        Movimiento(gusano[l].getRadio()*cos(aux_circulo[h])+posX[l],gusano[l].getRadio()*sin(aux_circulo[h])+posY[l],l);
						aux_circulo[h] -= 0.01;
					}			        
					/*Movimiento(30 * cos(aux) + posX[l] - 30, 30 * sin(aux) + posY[l], l);
					aux-=0.01;*/	
				}			
			}
			gfx_flush();
			usleep(41666); //24 por segundo
		}	
		//Movimientos aleatorios
		for(int p = 0; p < tamano_gusano; p++)
			gusano[p].setMovimiento(rand()%14);				
	}	
}

int main(){
	srand(time(NULL));	
	int numero_gusanos;
	cout << "Ingrese el numero de gusanos: ";
	cin >> numero_gusanos;
	//Tipo de movimiento a realizar	
	gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
	int tamano_gusano = numero_gusanos;
	gusano.resize(numero_gusanos);
	//Inicializar las posiciones de un gusano
	for(int i = 0; i < tamano_gusano; i++){
		gusano[i].setX((int)10 + rand() % 800);
		gusano[i].setY((int)10 + rand() % 600);
		gusano[i].setMovimiento(rand()%8);	
		gusano[i].setRadio(20+rand()%50);
	}
	funcion_Movimientos(tamano_gusano);	
	return 0;
}
