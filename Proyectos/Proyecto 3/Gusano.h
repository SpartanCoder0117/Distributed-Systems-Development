#ifndef GUSANO_H_
#define GUSANO_H_
class Gusano{
	private:
		int X;
		int Y;
		int movimiento_a_realizar;
		int radio;
	public:
		Gusano();
		int getX();
		int getY();
		int getMovimiento();
		int getRadio();
		void setX(int);
		void setY(int);
		void setMovimiento(int);
		void setRadio(int);
};
#endif


