#include "funciones.h"

#define NOM_ARCH_NUM1 "nro1.txt"
#define NOM_ARCH_NUM2 "nro2.txt"
#define NOM_ARCH_RESULTADO "resultado.txt"

int main()
{

    tPila pila1, pila2, resultado;
    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&resultado);

    cargarPilaDesdeArchivo(NOM_ARCH_NUM1, &pila1);
    cargarPilaDesdeArchivo(NOM_ARCH_NUM2, &pila2);

    sumarDigitosEnPilas(&pila1, &pila2, &resultado);
    grabarPilaArchivo(&resultado, NOM_ARCH_RESULTADO);

    return 0;
}
