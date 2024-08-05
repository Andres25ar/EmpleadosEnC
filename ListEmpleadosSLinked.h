#ifndef LISTEMPLEADOSSLINKED_H
#define LISTEMPLEADOSSLINKED_H

#include "Empleado.h"

typedef struct nodo{
    Empleado datum;
    struct nodo* next;
}T_Nodo;

typedef T_Nodo* T_Ptr;

typedef struct{
    T_Ptr lista;
    int tam;
}Lista;

Lista CargaListaSinRep();
void MostrarListaS(Lista);
int BuscarSLinked (Lista, long);
void AgregarNvo(Lista*);
int Tamanio(Lista);

#endif
