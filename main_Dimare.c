#include <stdio.h>
#include <stdlib.h>
#include "Driver_Dimare.h"
#include "Aplicacion_Dimare.h"

int main()
{
    temp_t temperatura;
    reporte_t reporte[CANT_SENSORES];
    unsigned int aux, corte, flag = 0;
    inicializacion(reporte);
    temperatura = obtener_temperatura();
    while(corte < TERMOCUPLAS_MAXIMAS)
    {
        do
        {
            aux = temperatura.numero;
            temperatura = obtener_temperatura();
            flag = 1;
            //printf("SENSOR: %d, TEMPERATURA: %d°C\n", temperatura.numero, temperatura.temp);      //Para realizar pruebas
        }while(aux == temperatura.numero || flag == 0);
        corte = generarReporte(reporte, temperatura, corte);
    }

    imprimir(reporte);

    return 0;
}
