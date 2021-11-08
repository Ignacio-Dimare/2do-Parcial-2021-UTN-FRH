#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED

typedef struct
{
    unsigned int numero;
    unsigned int temp;
} temp_t;

temp_t obtener_temperatura(void);


#endif // DRIVER_H_INCLUDED
