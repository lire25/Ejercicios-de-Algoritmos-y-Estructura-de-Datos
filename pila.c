#include "pila.h"
#include "utilidades.h"

void crearPila(tPila* pl)
{
    pl->tope = TAM;
}

void vaciarPila(tPila* pl)
{
    pl->tope = TAM;
}

int ponerEnPila(tPila* pl, const void* dato, unsigned cantbyte)
{
    if(pl->tope < cantbyte + sizeof(unsigned))
        return PILA_LLENA;
    pl->tope -= cantbyte;
    memcpy(pl->vec + pl->tope, dato, cantbyte);
    pl->tope -= sizeof(unsigned);
    memcpy(pl->vec + pl->tope, &cantbyte, sizeof(unsigned));
    return TODO_OK;
}

int sacarDePila(tPila* pl, void* dato, unsigned cantbyte)
{
    unsigned auxTamanio;
    if(TAM == pl->tope)
        return PILA_VACIA;
    memcpy(&auxTamanio, pl->vec + pl->tope, sizeof(unsigned));
    pl->tope += sizeof(unsigned);
    memcpy(dato, pl->vec + pl->tope, MINIMO(cantbyte, auxTamanio));
    pl->tope += auxTamanio;
    return TODO_OK;
}

int pilaLLena(const tPila* pl, unsigned cantbyte)
{
    return pl->tope < cantbyte + sizeof(unsigned);
}

int pilaVacia(const tPila* pl)
{
    return TAM == pl->tope;
}

int verTope(const tPila* pl, void* dato, unsigned cantbyte)
{
    unsigned auxTamanio;
    if(TAM == pl->tope)
        return PILA_VACIA;
    memcpy(&auxTamanio, pl->vec + pl->tope, sizeof(unsigned));
    memcpy(dato, pl->vec + pl->tope + auxTamanio, MINIMO(cantbyte, auxTamanio));
    return TODO_OK;
}
