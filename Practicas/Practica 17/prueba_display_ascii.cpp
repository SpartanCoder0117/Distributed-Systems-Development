#include <iostream>
#include <string.h>
#include <cmath>
#include "gfxModified.h"
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 180
#define PUNTOS 58

#define MICRO_SEC_PER_DAY 86400000000

int main() {
    struct timeval tiempo;
    time_t auxiliar;
    struct tm *timeinfo;
    gfx_open(ANCHURA, ALTURA, "Ejemplo gfx_display_ascii");
    char valor[12] = {42};
    int pre_dec = 0;
    int dec_sec;
    while(true) {
        gfx_color(87,1,2);
        
        gettimeofday(&tiempo, NULL);
        unsigned long algo = tiempo.tv_sec*1000000L + tiempo.tv_usec;
        long hms = algo % MICRO_SEC_PER_DAY;
        hms = (hms + MICRO_SEC_PER_DAY) % MICRO_SEC_PER_DAY;
        dec_sec = (hms % 1000000) / 10000;

        if (pre_dec == 0 || pre_dec != dec_sec){
            gfx_clear();
            pre_dec = dec_sec;
        }
        auxiliar = tiempo.tv_sec;
        timeinfo = localtime(&auxiliar);
        strftime(valor, 12, "%H:%M:%S", timeinfo);

        string valor2 = to_string(dec_sec);
        // decima de segundos
        gfx_display_ascii(610, 20, 10 , valor2.c_str()[0]);
        gfx_display_ascii(690, 20, 10 , valor2.c_str()[1]);

        // segundos
        gfx_display_ascii(410, 20, 10 , valor[6]);
        gfx_display_ascii(490, 20, 10 , valor[7]);

        // minutos
        gfx_display_ascii(210, 20, 10 , valor[3]);
        gfx_display_ascii(290, 20, 10 , valor[4]);

        // horas
        gfx_display_ascii(10, 20, 10 , valor[0]);
        gfx_display_ascii(90, 20, 10 , valor[1]);
        gfx_flush();
    }
    

}


