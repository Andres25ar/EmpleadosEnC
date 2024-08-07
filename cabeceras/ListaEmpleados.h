#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H

#include "Empleado.h"
#define TAM_LIST 25

typedef Empleado ListaEmpleados [TAM_LIST];

typedef struct {
    ListaEmpleados lista;
    int tam;
}EmpleadoArr;

EmpleadoArr CargarLista ();
void OrdenarLista (EmpleadoArr*);
void AgregarEmpleado (EmpleadoArr*);
void EliminarEmpleado (EmpleadoArr*);
int BuscarEmpleadoXDni (EmpleadoArr);
void VerTurnoMayoritario (EmpleadoArr);
void MostrarLista (EmpleadoArr);
void MostrarXTurno (EmpleadoArr);

#endif
