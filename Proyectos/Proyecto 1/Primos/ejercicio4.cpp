#include <vector>
#include <iostream>
using namespace std;

template <class T, class T2> 

class Primos{
    private:
        T numero;
        T verificar;
    public:
        Primos();
        void setNum(T numero){this-> numero = numero;}
        void setVerifi(T verificar){this-> verificar = verificar;}
        T getNum(){return numero;}
        T getVerifi(){return verificar;}
};

template <class T, class T2> 
Primos <T, T2>::Primos(){}

int main(){
    int n;
    cout << "Ingresa el valor de N: ";
    cin >> n;

    vector <Primos<int, bool>> numero;

    numero.reserve(n + 1);
    for(int i = 1; i < n; i++){
        numero[i].setNum(i);
        numero[i].setVerifi(true);
    }
    
    for(int i = 2; i < n; i++){
        for(int j = i; i * j < n; j++)
            numero[i * j].setVerifi(false);
    }

    for(int i = 2; i < n; i++){
        if(numero[i].getVerifi())
            cout << i << endl;
    }

    return 0;
}