#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Fechas.h"
#include "Cadena.h"

/*DNI, Apellido y Nombre, Fecha de Alta, Turno disponible (mañana, tarde y noche), Celular.*/
typedef struct{
	Fecha fechaAlta;
    SCadena nombre, apellido, celular;
    short turno;
    long dni;
}Empleado;

/*Todas las funciones correctamentes revisadas*/
Empleado CargaEmpleado (long);
short ReturnTurno (Empleado);
long ReturnDNI (Empleado);
void ModifEmpleado (Empleado*, long);
void MostrarEmpleado (Empleado);
void IntercambiaEmpleado(Empleado*, Empleado*); /*Funciona ok*/
Empleado CopyEmpleado (Empleado);               /*Funciona ok*/

#endif
