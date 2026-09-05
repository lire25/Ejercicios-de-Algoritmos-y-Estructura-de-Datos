#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X, Y)((X) < (Y)? (X): (Y))
#define TAM 1000

typedef struct
{
    char vec[TAM];
    unsigned tope;
}tPila;

void crearPila(tPila *pl);
void vaciarPila(tPila *pl);
int ponerEnPila(tPila *pl, const void *dato, unsigned cantbyte);
int sacarDePila(tPila *pl, void *dato, unsigned cantbyte);
int pilaLLena(const tPila *pl, unsigned cantbyte);
int pilaVacia(const tPila *pl);
int verTope(const tPila *pl, void *dato, unsigned cantbyte);

#endif // PILA_H_INCLUDED
