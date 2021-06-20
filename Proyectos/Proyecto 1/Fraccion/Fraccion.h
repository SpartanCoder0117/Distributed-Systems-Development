#ifndef FRACC_H_
#define FRACC_H_

class Fraccion
{
    private:
        int num;
        int deno;
    public:
        Fraccion();
        void setNum(int);
        void setDen(int);
        int getNum();
        int getDen();
        double Div(int, int);
        double *minima(int, int);
};
#endif
