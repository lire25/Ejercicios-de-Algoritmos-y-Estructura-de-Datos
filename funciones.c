#include "funciones.h"
#include "utilidades.h"


int abrirArchivo(FILE **fp, const char *nomArch, const char *modo)
{
    *fp = fopen(nomArch, modo);
    if(!fp)
    {
        fprintf(stderr,"Error al abrir el archivo %s \n", nomArch);
        return ERROR_ARCHIVO;
    }
    return TODO_OK;
}
int cargarPilaDesdeArchivo(const char *nombArch, tPila *pl)
{
    FILE *fp;
    char digito;
    if(abrirArchivo(&fp, nombArch, "rt") != TODO_OK)
        return ERROR_ARCHIVO;

    while(!pilaLLena(pl, sizeof(char)) && (digito = fgetc(fp)) != EOF)
    {
        if(ES_ENTERO(digito))
            ponerEnPila(pl, &digito, sizeof(char));
    }
    fclose(fp);
    return TODO_OK;
}

int sumarDigitosEnPilas(tPila *pila1, tPila *pila2, tPila *resultado)
{
    int numero1, numero2, carry = 0;
    char digito;
    while (!pilaVacia(pila1) && !pilaVacia(pila2))
    {
        sacarDePila(pila1, &digito, sizeof(char));
        numero1 = digito - '0';
        sacarDePila(pila2, &digito, sizeof(char));
        numero2 = digito - '0';
        carry += numero1 + numero2;
        digito = (carry % 10) + '0';
        carry /= 10;
        ponerEnPila(resultado, &digito, sizeof(char));
    }
    while(!pilaVacia(pila1))
    {
        sacarDePila(pila1, &digito, sizeof(char));
        numero1 = digito - '0' + carry;
        carry = numero1 / 10;
        digito = (numero1 % 10) + '0';
        ponerEnPila(resultado, &digito, sizeof(char));
    }

    while(!pilaVacia(pila2))
    {
        sacarDePila(pila2, &digito, sizeof(char));
        numero2 = digito - '0' + carry;
        carry = numero2 / 10;
        digito = (numero2 % 10) + '0';
        ponerEnPila(resultado, &digito, sizeof(char));
    }

    if(carry != 0 && pilaVacia(pila1) && pilaVacia(pila2))
    {
        digito = (carry % 10) + '0';
        ponerEnPila(resultado, &digito, sizeof(char));
    }

    return TODO_OK;
}

int grabarPilaArchivo(tPila *pila1, const char *nombArch)
{
    FILE *fp;
    char digito;
    if(abrirArchivo(&fp, nombArch, "wt") != TODO_OK)
        return ERROR_ARCHIVO;
    while(!pilaVacia(pila1))
    {
        sacarDePila(pila1, &digito, sizeof(char));
        fputc(digito, fp);
    }
    fputc('\n',fp);
    fclose(fp);
    return TODO_OK;
}

