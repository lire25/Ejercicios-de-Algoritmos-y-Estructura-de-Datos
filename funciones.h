#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "pila.h"

int sumar (char *num1, char *num2);
int sumarDigitosEnPilas(tPila *pila1, tPila *pila2, tPila *resultado);
int grabarPilaArchivo(tPila *pila1, const char *nombArch);

int cargarPilaDesdeArchivo(const char *nombArch, tPila *pl);
int abrirArchivo(FILE **fp, const char *nomArch, const char *modo);


#endif // FUNCIONES_H_INCLUDED
