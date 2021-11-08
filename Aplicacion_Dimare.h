#ifndef APLICACION_H_INCLUDED
#define APLICACION_H_INCLUDED

#include "Driver_Dimare.h"

#define CANT_SENSORES 60
#define TEMP_SUPERIOR 600
#define TEMP_DE_CORTE 800
#define TERMOCUPLAS_MAXIMAS 5

typedef struct
{
    unsigned int acum;
    float prom;
    unsigned int maximo;
    unsigned int cantMax;
    unsigned int cant;
}reporte_t;

void inicializacion(reporte_t reporte[]);
unsigned int generarReporte(reporte_t reporte[], temp_t temperatura, unsigned int corte);
void imprimir(reporte_t reporte[]);

#endif // APLICACION_H_INCLUDED
