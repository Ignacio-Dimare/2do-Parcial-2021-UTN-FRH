#include "Driver_Dimare.h"
#include "Mock.h"

#define PUERTO_0 0xA00
#define PUERTO_1 0xA01
#define PUERTO_2 0xA02
#define SHIFT_PUERTO 8
#define MASK_PUERTO2 0xFF00
#define MASK_PUERTO1 0xFFFF00
#define SHIFT_NUMERO 5
#define MASK_NUMERO 0x3F
#define SHIFT_TEMPERATURA 2
#define MASK_TEMPERATURA 0xFF
#define SHIFT_ESCALA 10
#define MASK_ESCALA 0x01

temp_t obtener_temperatura(void)
{
    temp_t temp;
    unsigned int byte0, byte1, byte2, escala, valorEmpaquetado;
    byte0 = inb(PUERTO_0);
    byte1 = inb(PUERTO_1);
    byte2 = inb(PUERTO_2);

    valorEmpaquetado = byte2;
    valorEmpaquetado = valorEmpaquetado << SHIFT_PUERTO;
    valorEmpaquetado = (valorEmpaquetado & MASK_PUERTO2) | byte1;

    temp.numero = (valorEmpaquetado >> SHIFT_NUMERO) & MASK_NUMERO;

    valorEmpaquetado = byte1;
    valorEmpaquetado = valorEmpaquetado << SHIFT_PUERTO;
    valorEmpaquetado = (valorEmpaquetado & MASK_PUERTO1) | byte0;

    temp.temp = (valorEmpaquetado >> SHIFT_TEMPERATURA) & MASK_TEMPERATURA;
    escala = (valorEmpaquetado >> SHIFT_ESCALA) & MASK_ESCALA;
    if(escala == 1)
        temp.temp *= 10;
    return temp;
}
