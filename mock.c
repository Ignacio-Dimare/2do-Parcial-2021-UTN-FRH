#include "mock.h"
#include <stdio.h>
#include <stdlib.h>
//Configuracion de bits de validez
#define a 1//Repeticiones del bit 0
#define b 3 //Repeticiones de los bits =! de 0
#define CANT_BITS_VALIDEZ 3 //Valor maximo que puden tomar los bits de validez

#define VELOCIDAD_MINIMA_1 7890
#define VELOCIDAD_MAXIMA_1 12110
#define VELOCIDAD_MINIMA_2 13890
#define VELOCIDAD_MAXIMA_2 16110

#define CANTIDAD_CENTRIFUGAS 7

//SHIFT
#define n 		5
#define o_1        0x40
#define o_2        0x20
#define f 	7

#define g 	13
#define h_1 0xC000
#define h_2 0x2000
#define k 	5
#define l 	0x1FC0
#define m 	3
#define e	0x001C
#define x	0x0003

#define P_2 0xA02
#define P_1 0xA01
#define P_0 0xA00


unsigned char generarValidez(void);
unsigned int contador_lecturas = 0;


unsigned char generarValidez(void)
{
    static unsigned char cant_enviados = 0, validez = 1 ;  //Variable de 1 Byte statica no signada, se inicializa en 0
                                                         //solo la primera vez que se ejecuta la funcion
    unsigned char valorDevuelto ;

    if (cant_enviados < a)
        valorDevuelto = 0 ;
    else
    {
        valorDevuelto = validez ;
    }

    cant_enviados++;

    if ( cant_enviados >= (a + b) )
    {
        validez++ ;
        cant_enviados = 0 ;
    }

    if (validez > CANT_BITS_VALIDEZ)
        validez = 1 ;

    return valorDevuelto;
}



unsigned char inb (unsigned int puerto)
{

    unsigned char byte_devuelto = 0;


    int jose ;
    int maria = 0 ;

    int marcos = (int)(contador_lecturas*7) % 25 ;

    jose = (int)(contador_lecturas*3/(marcos%4+1))+100  ;



    if (jose > 255)
    {
        jose =  jose / 10 ;
        maria = 1 ;
    }

    if(puerto==P_0)
	{
        contador_lecturas++;
        byte_devuelto = (jose<<2 & 0xff);
    }

    if(puerto==P_1)
	{
        byte_devuelto = ((jose>>6)&3) ;
        byte_devuelto |= maria<<2;
        byte_devuelto |= (marcos<<5 & 0xff);
	}

    if(puerto==P_2)
	{
        byte_devuelto = ((marcos>>3)&3) ;
	}
    return byte_devuelto;
}
