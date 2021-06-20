#ifndef TEMP_H_
#define TEMP_H_

class Temperatura
{
    private:
        int kelvin;
        int celsius;
        int fahrenheit;    
    public:
        Temperatura();
        void setK(int);
        void setF(int);
        void setC(int);
        int getK();
        int getF();
        int getC();
        double K_C(int);
        double K_F(int);
};
#endif
