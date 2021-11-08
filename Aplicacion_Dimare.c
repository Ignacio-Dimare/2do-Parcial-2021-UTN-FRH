#include <stdio.h>
#include "Aplicacion_Dimare.h"

void inicializacion(reporte_t reporte[])
{
    for(int i=0; i<CANT_SENSORES; i++)
    {
        reporte[i].acum = 0;
        reporte[i].cant = 0;
        reporte[i].cantMax = 0;
        reporte[i].maximo = 0;
        reporte[i].prom = 0;
    }
}

unsigned int generarReporte(reporte_t reporte[], temp_t temperatura, unsigned int corte)
{
    reporte[temperatura.numero].acum += temperatura.temp;
    reporte[temperatura.numero].cant++;
    reporte[temperatura.numero].prom = (float)reporte[temperatura.numero].acum/reporte[temperatura.numero].cant;

    corte = 0;
    for(int i=0; i<CANT_SENSORES; i++)
    {
        if(reporte[i].prom > TEMP_DE_CORTE)
            corte++;
    }

    if(temperatura.temp > reporte[temperatura.numero].maximo)
        reporte[temperatura.numero].maximo = temperatura.temp;

    if(temperatura.temp > TEMP_SUPERIOR)
    {
        reporte[temperatura.numero].cantMax +=1;
    }

    return corte;
}


void imprimir(reporte_t reporte[])
{
    for(int i=0; i<CANT_SENSORES;i++)
    {
        printf("Termocupla: %d\tPromedio: %.2f°C\tMediciones: %d\tMediciones>600: %d\tTemperatura maxima: %d°C\n", i, reporte[i].prom, reporte[i].cant, reporte[i].cantMax, reporte[i].maximo);
    }
}
